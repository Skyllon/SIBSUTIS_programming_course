#include "../libs/frequency_logic.h"

#include <locale.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>
#include <wctype.h>

static const wchar_t vowels[] = L"aeiouyаеёиоуыэюяAEIOUYАЕЁИОУЫЭЮЯ";

int compare_entries(const void *a, const void *b) {
    const struct Entry *entryA = *(const struct Entry **)a;
    const struct Entry *entryB = *(const struct Entry **)b;

    return entryB->value - entryA->value;
}

struct Stats init(void) {
    struct Stats stats = {0};
    memset(stats.len_stats, 0, sizeof(stats.len_stats));

    return stats;
}

int starts_with_vowel(const wchar_t *word) {
    if (!word || *word == L'\0') return 0;

    return wcschr(vowels, towlower(word[0])) != NULL;
}

void update_stats(struct Stats *stats, const wchar_t *word) {
    if (!stats || !word) return;

    size_t len = wcslen(word);
    if (len > 0 && len <= MAX_WORD_LENGTH) stats->len_stats[len]++;
    (starts_with_vowel(word)) ? stats->wvc++ : stats->ctc++;

    stats->ttw++;
}

void process_text(const char *filename, struct HashTable *table,
                  struct Stats *stats) {
    FILE *file = fopen(filename, "rb");

    if (!file) {
        perror("Ошибка открытия файла");

        return;
    }

    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    rewind(file);
    char *buffer = malloc(file_size + 1);

    if (!buffer) {
        perror("Ошибка выделения памяти");
        fclose(file);

        return;
    }

    size_t bytes_read = fread(buffer, 1, file_size, file);

    if (bytes_read != (size_t)file_size) {
        perror("Ошибка чтения файла");
        free(buffer);
        fclose(file);

        return;
    }

    buffer[file_size] = '\0';
    setlocale(LC_ALL, "ru_RU.UTF-8");
    wchar_t *wbuffer = malloc((file_size + 1) * sizeof(wchar_t));
    size_t converted = mbstowcs(wbuffer, buffer, file_size);
    free(buffer);

    if (converted == (size_t)-1) {
        perror("Ошибка конвертации");
        fclose(file);
        free(wbuffer);

        return;
    }

    wchar_t *saveptr;
    wchar_t *token = wcstok(wbuffer, L" ,.!?;:\t\n", &saveptr);

    while (token) {
        char narrow_word[256];
        wcstombs(narrow_word, token, sizeof(narrow_word));
        add_hash(table, narrow_word);
        update_stats(stats, token);
        token = wcstok(NULL, L" ,.!?;:\t\n", &saveptr);
    }

    free(wbuffer);
    fclose(file);
}

void print_results(const struct HashTable *table, const struct Stats *stats,
                   const char *filename, double elapsed_time) {
    FILE *out = fopen(filename, "w");

    if (!out) {
        perror("Ошибка открытия файла");
        return;
    }

    struct Entry **entries = malloc(table->size * sizeof(struct Entry *));
    size_t count = 0;

    for (size_t i = 0; i < table->capacity; i++) {
        struct Entry *entry = table->buckets[i];
        while (entry) {
            if (entry->value > 1) entries[count++] = entry;
            entry = entry->next;
        }
    }

    qsort(entries, count, sizeof(struct Entry *), compare_entries);

    if (count > 0) {
        fprintf(out, "Частота словС\n");
        for (size_t i = 0; i < count; i++)
            fprintf(out, "%s - %d\n", entries[i]->key, entries[i]->value);
    } else
        fprintf(out, "Нет слов с частотой > 1.\n");

    fprintf(out, "\nСтатистика:\n");
    fprintf(out, "Слов на гласные: %zu\n", stats->wvc);
    fprintf(out, "Слов на согласные: %zu\n", stats->ctc);

    fprintf(out, "\nДлина слова по буквам:\n");
    for (int i = 1; i <= MAX_WORD_LENGTH; i++) {
        if (stats->len_stats[i] > 0) {
            fprintf(out, "%2d букв: %zu\n", i, stats->len_stats[i]);
        }
    }

    fprintf(out, "\nВремя выполнения: %.3f секунд\n", elapsed_time);

    free(entries);
    fclose(out);
}
