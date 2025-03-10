//
// Created by Heros on 10/03/2025.
//

#include "trie.h"

#define PSIZE 256

typedef struct trie{
    int exists;
    struct trie * pointers[PSIZE];
}* trie;

trie trie_init(){
    trie t = malloc(sizeof(struct trie));

    t->exists = 0;

    for(int i = 0; i < PSIZE; i++)
        t->pointers[i] = NULL;

    return t;
}

void trie_free(trie t){
    if(t == NULL)
        return;

    for(int i = 0; i < PSIZE; i++)
        trie_free(t->pointers[i]);

    free(t);
}

void trie_add(trie t, void * data, size_t data_len){
    if(data_len == 0) {
        t->exists = 1;
        return;
    }

    unsigned char pos = *(unsigned char *)data;

    if(t->pointers[pos] == NULL){
        t->pointers[pos] = trie_init();
    }

    trie_add(t->pointers[pos], data+1, data_len-1);
}

int  trie_if_exists(trie t, void * data, size_t data_len){
    if(data_len == 0)
        return t->exists;

    unsigned char pos = *(unsigned char *)data;

    if(t->pointers[pos] == NULL){
        return 0;
    }

    return trie_if_exists(t->pointers[pos], data+1, data_len-1);
}