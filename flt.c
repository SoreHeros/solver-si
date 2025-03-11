//
// Created by Heros on 11/03/2025.
//

#include "flt.h"

typedef unsigned char byte;


typedef struct flt{
    int states, depth;
    byte arr[];
} * flt;

flt_key ipow(int base, int exp){
    flt_key ret = 1;

    while(exp){
        if(exp%2){
            ret *= base;
        }

        exp  /= 2;
        base *= base;
    }

    return ret;
}

flt     flt_init(int states, int depth){
    size_t size = ipow(states, depth) / 8 + 1;
    flt f = malloc(sizeof(struct flt) + size);
    f->states = states;
    f->depth = depth;

    for(int i = 0; i < size; i++)
        f->arr[i] = 0;

    return f;
}
void    flt_free(flt f){
    free(f);
}

flt_key flt_get_key(flt f, int * data){
    flt_key k = 0;

    for(int i = 0; i < f->depth; i++){
        k *= f->states;
        k += data[i];
    }

    return k;
}
bool    flt_get_state(flt f, flt_key k){
    size_t byte = k / 8;
    int bit = k % 8;

    return f->arr[byte] & (0b1 << bit) ? true : false;
}
void    flt_set_state(flt f, flt_key k, bool state){
    byte * b = &f->arr[k / 8];
    int bit = k % 8;

    *b &= ~(0b1 << bit); // limpiar bit

    if(state)
        *b |= 0b1 << bit; // añadir bit si necesario
}