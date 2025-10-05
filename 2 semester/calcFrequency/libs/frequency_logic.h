#ifndef FREQUENCY_LOGIC_H
#define FREQUENCY_LOGIC_H

#include <ctype.h>
#include <locale.h>
#include <stddef.h>
#include <string.h>
#include <wchar.h>
#include <wctype.h>

#include "hash_table.h"

#define MAX_WORD_LENGTH 50

/*
    @brief: Statistics for file

    @field: ttc - total chars
    @field: ttw - total words
    @field: wvc - from vowels count in text
    @field: ctc - from conconants count in text
    @field: len_stats - words by length
*/

struct Stats {
    size_t ttc;
    size_t ttw;
    size_t wvc;
    size_t ctc;
    size_t len_stats[MAX_WORD_LENGTH + 1];
};

/*
    @brief: initialize statistics

    @param: void

    @return: struct Stats - initialized statistics
*/
struct Stats init(void);

/*
    @brief: update statistics

    @param: stats - structure of statistics
    @param: word - word to analyze

    @return: void
*/
void upd_stats(struct Stats *stats, const wchar_t *word);

/*
    @brief: Check if word starts with vowel

    @param: word - word to analyze

    @return: 1 if word starts with vowel, 0 otherwise
*/
int with_vowel(const wchar_t *word);

/*
    @brief: Process text file

    @param: filename - name of file to process
    @param: table - hash table to store words
    @param: stats - structure of statistics

    @return: void
*/
void process_text(const char *filename, struct HashTable *table,
                  struct Stats *stats);

/*
    @brief: Print results to file

    @param: table - hash table to print
    @param: stats - structure of statistics
    @param: filename - name of file to print

    @return: void
*/
void print_results(const struct HashTable *table, const struct Stats *stats,
                   const char *filename, double elapsed_time);

/*
    @brief: Sort words by frequency

    @param: entries - array of words
    @param: count - number of words

    @return: void
*/
void bubble_sort(struct Entry **entries, size_t count);

/*
    @brief: comparator for qsort

    @param: a - first entry
    @param: b - second entry

    @return: sorted entries
*/
int compare_entries(const void *a, const void *b);

#endif
