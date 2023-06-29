#ifndef BLOOMC_BLOOM_H
#define BLOOMC_BLOOM_H

typedef struct {
    int size; // size of bloom filter
    int numHashes; // number of hash functions
    char *filter; // bloom filter
} BloomFilter;

void bloom_add(BloomFilter *bloom, char *str);
static void bloom_filter_insert(BloomFilter *bloom, unsigned int index);
static int bloom_filter_check(BloomFilter *bloom, unsigned int index);
int bloom_check(BloomFilter *bloom, char *str);
BloomFilter *bloom_init(int size, int numHashes);
void bloom_free(BloomFilter *bloom);

#endif //BLOOMC_BLOOM_H