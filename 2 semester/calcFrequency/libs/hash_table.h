#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LOAD_FACTOR 0.7
#define INIT_TABLE_SIZE 2056

/*
    @brief: Bucket for hash table

    @field: key - string
    @field: value - frequency
    @field: idx - index
    @field: next - pointer to next bucket
*/
struct Entry {
    char *key;
    int value;
    unsigned int idx;
    struct Entry *next;
};

/*
    @brief: Hash table

    @field: size - size of hash table
    @field: table - array of buckets
*/
struct HashTable {
    size_t size;
    size_t capacity;
    struct Entry **buckets;
};

/*
    @brief: K&R hash func for index

    @param: key - string for hash

    @return: index of hashed string
*/
unsigned int KRhash(const char *key);

/*
    @brief: Init hash table

    @param: size - size of hash table

    @return: initialized hash table
*/
struct HashTable *init_hash(void);

/*
    @brief: Add element to hash table

    @param: table - hash table to add element
    @param: key - string

    @return: void
*/
void add_hash(struct HashTable *table, const char *key);

/*
    @brief: Find element in hash table

    @param: table - hash table to find element
    @param: hash_index - index of element

    @return: void
*/
int find_hash(const struct HashTable *table, const char *key);

/*
    @brief: Free hash table

    @param: table - hash table to free
*/
void free_hash(struct HashTable *table);

/*
    @brief: Resize table if initial size isn't enough

    @param: table - hash table to resize

    @return: resized hash table
*/
struct HashTable *resize_table(struct HashTable *table);

#endif
