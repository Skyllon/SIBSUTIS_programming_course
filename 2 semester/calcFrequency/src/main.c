#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>

#include "../libs/frequency_logic.h"
#include "../libs/hash_table.h"

int main(int argc, char **argv) {
    if (argc != 3) {
        printf("Использование: %s <входной_файл> <выходной_файл>\n", argv[0]);
        return EXIT_FAILURE;
    }

    struct timeval start, end;
    gettimeofday(&start, NULL);

    struct HashTable *table = init_hash();
    struct Stats stats = init();
    process_text(argv[1], table, &stats);

    gettimeofday(&end, NULL);
    double elapsed =
        (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) / 1000000.0;

    print_results(table, &stats, argv[2], elapsed);
    free_hash(table);

    return EXIT_SUCCESS;
}
