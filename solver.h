//
// Created by Heros on 07/03/2025.
//

#ifndef SOLVER_SI_SOLVER_H
#define SOLVER_SI_SOLVER_H

void solver_set_params(void * (* init)(), void ** (* step)(void *), int (* isEnd)(void *)); //init return an initial board state; step return a null-terminated array of possible next boards; isEnd returns 1 if the board is a valid end state, 0 otherwise

void solver_calculate();

#endif //SOLVER_SI_SOLVER_H
