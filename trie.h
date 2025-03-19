//
// Created by Heros on 10/03/2025.
//

#ifndef SOLVER_SI_TRIE_H
#define SOLVER_SI_TRIE_H

#include <stdlib.h>

typedef struct trie * trie;
typedef trie trie_val;

trie trie_init();
void trie_free(trie);

trie_val trie_add(trie, void * data, size_t data_len);
trie_val trie_search(trie, void * data, size_t data_len);

void trie_remove(trie, void * data, size_t data_len);
void * trie_backtrace(trie_val, size_t * data_len);

#endif //SOLVER_SI_TRIE_H
