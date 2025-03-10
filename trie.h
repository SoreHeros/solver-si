//
// Created by Heros on 10/03/2025.
//

#ifndef SOLVER_SI_TRIE_H
#define SOLVER_SI_TRIE_H

#include <stdlib.h>

typedef struct trie * trie;

trie trie_init();
void trie_free(trie);

void trie_add(trie, void * data, size_t data_len);
int  trie_if_exists(trie, void * data, size_t data_len);

#endif //SOLVER_SI_TRIE_H
