//
// Created by Heros on 11/03/2025.
//

#ifndef SOLVER_SI_FLT_H
#define SOLVER_SI_FLT_H

#include <stdlib.h>
#include <stdbool.h>

//flat last trie

typedef struct flt * flt;
typedef size_t flt_key;

flt     flt_init(int states, int depth);
void    flt_free(flt);

flt_key flt_get_key(flt, int * data);
bool    flt_get_state(flt, flt_key);
void    flt_set_state(flt, flt_key, bool state);

#endif //SOLVER_SI_FLT_H
