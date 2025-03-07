//
// Created by Heros on 07/03/2025.
//

#include "solver.h"
#include "lists.h"

void * (*init)();
void ** (* step)(void *);
int (* isEnd)(void *);

void solver_set_params(void * (* a)(), void ** (* b)(void *), int (* c)(void *)){
    init = a;
    step = b;
    isEnd = c;
} //init return an initial board state; step return a null-terminated array of possible next boards; isEnd returns 1 if the board is a valid end state, 0 otherwise

void solver_calculate(){
    list current = list_init(), next = list_init();
    list_append(current, init());
    int index = 0;

    while(!isEnd(list_get(current, index))){

    }
}