//
// Created by Heros on 07/03/2025.
//

#include "lists.h"


#include "lists.h"
#include <stdlib.h>
#include <stdio.h>

//internal functions
struct list{
    void ** data;
    int data_len;
    int list_len;
};

int resize_list(list l){
    void * aux = realloc(l->data, l->data_len * 2 * sizeof(void *));
    if(aux == NULL){
        return 0;
    }
    l->data = aux;
    l->data_len *= 2;
    return 1;
}


//mem management instructions
list list_init(){
    list l = malloc(sizeof(struct list));

    l->data = malloc(sizeof(void *));
    l->data_len = 1;
    l->list_len = 0;

    return l;
}
void list_free(list l){
    free(l->data);
    l->data = NULL;
    l->list_len = 0;
    l->data_len = 0;
    free(l);
}

//list management
void list_append(list l , void * element){
    if(l->list_len >= l->data_len){
        if(!resize_list(l)){
            perror("ERROR AL AUMENTAR EL TAMANO DE LA LISTA");
            return;
        }
    }
    l->data[l->list_len++] = element;
}
void * list_pop(list l){
    l->list_len--;
    return l->data[l->list_len];
}
void list_remove(list l, int pos){
    for(int i = pos + 1; i < l->list_len; i++)
        l->data[i - 1] = l->data[i];
    l->list_len--;
}
void list_add(list l, int pos, void * element){
    if(l->list_len >= l->data_len){
        if(!resize_list(l)){
            perror("ERROR AL AUMENTAR EL TAMANO DE LA LISTA");
            return;
        }
    }
    //crear hueco
    for(int i = l->list_len; i > pos; i--)
        l->data[i] = l->data[i - 1];
    l->data[pos] = element;
    l->list_len++;
}

//element management
void * list_get(list l, int pos){
    return l->data[pos];
}
void list_set(list l, int pos, void * element){
    l->data[pos] = element;
}
int list_search(list l, void * element, int (* comparator)(const void *, const void *)){
    for(int i = 0; i < l->list_len; i++){
        if(!comparator(element, l->data[i]))
            return i;
    }
    return -1;
}
int list_length(list l){
    return l->list_len;
}