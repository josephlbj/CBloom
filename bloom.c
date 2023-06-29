#include <malloc.h>
#include <string.h>
#include "murmur.h"
#include "bloom.h"

void bloom_add(BloomFilter *bloom, char *str){
    for (int i = 0; i < bloom->numHashes; ++i) {
        unsigned int hash_val = MurmurHash1(str, strlen(str), i) % bloom->size;
        bloom_filter_insert(bloom, hash_val);
    }
}

static void bloom_filter_insert(BloomFilter *bloom, unsigned int index){
    int corrected_index = index / 8;
    int past_index = index % 8;

    bloom->filter[corrected_index] |= 1 << (7 - past_index);
}

int bloom_check(BloomFilter *bloom, char *str) {
    int total = 0;
    for (int i = 0; i < bloom->numHashes; ++i) {
        int hash_val = MurmurHash1(str, strlen(str), i) % bloom->size;
        total += bloom_filter_check(bloom, hash_val);
    }

    return total == bloom->numHashes;
}

static int bloom_filter_check(BloomFilter *bloom, unsigned int index){
    int corrected_index = index / 8;
    int past_index = index % 8;

    int exists = bloom->filter[corrected_index] & 1 << (7 - past_index);
    return exists > 0;
}

BloomFilter *bloom_init(int size, int numHashes) {
    BloomFilter *bloom = malloc(sizeof(BloomFilter));
    bloom->size = size;
    bloom->numHashes = numHashes;

    // Calculating the size of the bloom filter in bytes
    int filter_length = size / 8;
    bloom->filter = calloc(size + 1, filter_length);
    return bloom;
}

void bloom_free(BloomFilter *bloom) {
    free(bloom->filter);
    free(bloom);
}
