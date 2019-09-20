#include "LinkedList.h"

LinkedList *new_linked_list(){
    LinkedList *nn = malloc(sizeof(LinkedList));
    nn->elements = 0;
    nn->HEAD = NULL;
    nn->Iterator = NULL;
    return nn;
};

void get_iterators(LinkedList *linkedlist){
    if(linkedlist->HEAD){

    free(linkedlist->Iterator);
    NODE **array_of_nodes = malloc(sizeof(NODE *) * linkedlist->elements);
    NODE *node = linkedlist->HEAD;

    int i;
    for(i = 0; node; node = node->next) array_of_nodes[i++] = node;
    linkedlist->Iterator = array_of_nodes;
    }
}



void add_node_pointer(LinkedList *linkedlist, NODE *np){
    np->next = linkedlist->HEAD;
    linkedlist->HEAD = np;
    linkedlist->elements++;
};

NODE * get_node_pointer(LinkedList *linkedlist, void *key)
{

    NODE *current = linkedlist->HEAD;
    while(current && linkedlist->equals(current->str, key)) current = current->next;
    return current;

};

int add_new_node(LinkedList *linkedlist, void *key, void *value){

    NODE *new_node = malloc(sizeof(NODE));
    new_node->value = value;
    new_node->str = key;
    new_node->next = linkedlist->HEAD;
    linkedlist->HEAD = new_node;
    return linkedlist->elements++;

};

void *get_node(LinkedList *linkedlist, void *node_to_search){

    NODE *current = linkedlist->HEAD;
    while(current && linkedlist->equals(current->key, node_to_search)) current = current->next;

    if(current) return current->value;
    return NULL;

};


void *remove_node(LinkedList *linkedlist, char *s){

    void *value_from_linkedlist;
    NODE *current = linkedlist->HEAD;
    NODE *elozo = NULL;

    while(current && strcmp(current->str, s)) {
            elozo = current;
            current = current->next;
    }

    if(current){

        value_from_linkedlist = current->value;
        linkedlist->elements--;

        if(elozo) elozo->next = current->next;
        else linkedlist->HEAD = current->next;

        free(current);
        return value_from_linkedlist;
    }

    return NULL;
};


