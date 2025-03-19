//
// Created by Heros on 10/03/2025.
//

#include "trie.h"

#define PSIZE 256

typedef struct trie{
    // mutex
    struct trie * prev;
    int children;
    char exists;
    unsigned char pos;
    struct trie * pointers[PSIZE];
}* trie;

size_t trie_val_depth(trie_val t){
    if(t->prev == NULL)
        return 0;

    return trie_val_depth(t->prev) + 1;
}

trie trie_init_intern(trie father, unsigned char pos){
    trie t = malloc(sizeof(struct trie));

    t->exists = 0;
    t->pos = pos;
    t->prev = father;
    t->children = 0;

    for(int i = 0; i < PSIZE; i++)
        t->pointers[i] = NULL;

    return t;
}

trie trie_init(){
    return trie_init_intern(NULL, 0);
}

void trie_free(trie t){
    if(t == NULL)
        return;

    for(int i = 0; i < PSIZE; i++)
        trie_free(t->pointers[i]);

    free(t);
}

trie_val trie_add(trie t, void * data, size_t data_len){
    // lock t
    // if(t->prev != NULL)
    //   unlock t->prev
    if(data_len == 0) {
        t->exists = 1;
        // unlock t
        return t;
    }

    unsigned char pos = *(unsigned char *)data;

    if(t->pointers[pos] == NULL){
        t->pointers[pos] = trie_init_intern(t, pos);
    }

    t->children++;

    return trie_add(t->pointers[pos], data+1, data_len-1);
}

trie_val trie_search(trie t, void * data, size_t data_len){
    // lock t
    // if t->prev != NULL
    // unlock t->prev
    if(data_len == 0) {
        trie_val ret = t->exists ? t : NULL;;
        // unlock t
        return ret;
    }
    unsigned char pos = *(unsigned char *)data;

    if(t->pointers[pos] == NULL){
        // unlock t
        return NULL;
    }
    return trie_search(t->pointers[pos], data+1, data_len-1);
}

void trie_remove(trie t, void * data, size_t data_len){
    //lock t
    //if(t->prev != NULL)
    //  unlock t-prev

    if(data_len == 0) {
        if(t->children == 0) {
            free(t);
        }
        return;
    }

    unsigned char pos = *(unsigned char *)data;

    t->children--;

    trie aux = t->pointers[pos];


    //lock aux
    if(!t->children)
        free(t);
        //aux->prev = NULL;
    else {
        if (aux->children == 1)
            t->pointers[pos] = NULL;
    }
    //unlock aux

    trie_remove(aux, data+1, data_len-1);
}



void * trie_backtrace(trie_val t, size_t * len){
    *len = trie_val_depth(t);
    unsigned char * ret = malloc(*len);

    for(int i = *len - 1; i >= 0; i--){
        ret[i] = t->pos;
        t = t->prev;
    }

    return ret;
}
