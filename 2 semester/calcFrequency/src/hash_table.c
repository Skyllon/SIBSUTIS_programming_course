#include "../libs/hash_table.h"

unsigned int KRHash(const char *key) {
    unsigned int h = 0;
    unsigned int hash_mul = 31;

    while (*key) h = h * hash_mul + (unsigned int)*key++;
    return h % INIT_TABLE_SIZE;
}

struct HashTable *init_hash(void) {
    struct HashTable *table = malloc(sizeof(struct HashTable));

    if (!table) {
        perror("Ошибка: память не была аллоцирована!\n");
        return NULL;
    }

    table->capacity = INIT_TABLE_SIZE;
    table->size = 0;
    table->buckets = calloc(table->capacity, sizeof(struct Entry *));
    memset(table->buckets, 0, table->capacity);

    if (!table->buckets) {
        perror("Ошибка: память не была аллоцирована для корзин!\n");
        free(table);
        return NULL;
    }

    return table;
}

void add_hash(struct HashTable *table, const char *key) {
    if ((double)table->size / table->capacity > LOAD_FACTOR) {
        table = resize_table(table);
    }

    unsigned int idx = KRHash(key) % table->capacity;
    struct Entry *entry = table->buckets[idx];

    /* Search existing key */
    while (entry) {
        if (strcmp(entry->key, key) == 0) {
            entry->value++;
            return;
        }
        entry = entry->next;
    }

    /* Create new entry */
    struct Entry *new_entry = malloc(sizeof(struct Entry));
    memset(new_entry, 0, sizeof(struct Entry));
    new_entry->key = strdup(key);
    new_entry->value = 1;
    new_entry->next = table->buckets[idx];
    table->buckets[idx] = new_entry;
    table->size++;
}

int find_hash(const struct HashTable *table, const char *key) {
    if (!table || !key || table->capacity == 0) return 0;

    unsigned int idx = KRHash(key) % table->capacity;
    struct Entry *entry = table->buckets[idx];

    /* Iterate over linked list (check all collisions)*/
    while (entry) {
        if (strcmp(entry->key, key) == 0) {
            return entry->value; /* Word found */
        }
        entry = entry->next;
    }

    return 0; /* Word not found */
}

struct HashTable *resize_table(struct HashTable *table) {
    size_t new_capacity = table->capacity * 2;
    struct Entry **new_buckets = calloc(new_capacity, sizeof(struct Entry *));
    if (!new_buckets) return table;

    /* Rehash all elements */
    for (size_t i = 0; i < table->capacity; i++) {
        struct Entry *entry = table->buckets[i];
        while (entry) {
            struct Entry *next = entry->next;
            unsigned int new_idx = KRHash(entry->key) % new_capacity;

            /* Insert in new table */
            entry->next = new_buckets[new_idx];
            new_buckets[new_idx] = entry;
            entry = next;
        }
    }

    free(table->buckets);
    table->buckets = new_buckets;
    table->capacity = new_capacity;

    return table;
}

void free_hash(struct HashTable *table) {
    if (!table) return;

    for (size_t i = 0; i < table->capacity; i++) {
        struct Entry *entry = table->buckets[i];

        while (entry) {
            struct Entry *next = entry->next;
            free(entry->key);
            free(entry);
            entry = next;
        }
    }

    free(table->buckets);
    free(table);
}
