#include <stdio.h>
#include "bloom.h"

int main(){
    BloomFilter *bloom = bloom_init(100, 3);
    bloom_add(bloom, "item1");
    bloom_add(bloom, "item2");

    printf("item1: %d\n", bloom_check(bloom, "item1"));
    printf("item2: %d\n", bloom_check(bloom, "item2"));
    printf("item3: %d\n", bloom_check(bloom, "item3"));
    printf("item4: %d\n", bloom_check(bloom, "item4"));

    bloom_free(bloom);
    return 0;
}