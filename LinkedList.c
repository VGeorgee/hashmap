#include "include/LinkedList.h"

LinkedList *new_linked_list(int (* equals)(const void *a, const void*b), int (* hashcode)(const void *a)){
    LinkedList *linked_list = malloc(sizeof(LinkedList));
    linked_list->elements = 0;
    linked_list->HEAD = NULL;
    linked_list->Iterator = NULL;
    linked_list->equals = equals;
    linked_list->hashcode = hashcode;
    return linked_list;
};

void get_iterators(LinkedList *linkedlist){

    if(linkedlist->HEAD){
        free(linkedlist->Iterator);
        NODE **array_of_nodes = malloc(sizeof(NODE *) * linkedlist->elements);
        NODE *node = linkedlist->HEAD;

        int i;
        for(i = 0; node; node = node->next){
            array_of_nodes[i++] = node;
        }
        linkedlist->Iterator = array_of_nodes;
    }
}

void add_node_pointer(LinkedList *linkedlist, NODE *np){
    np->next = linkedlist->HEAD;
    linkedlist->HEAD = np;
    linkedlist->elements++;
};

NODE *create_new_node(void *key, void *value){
    NODE *new_node = malloc(sizeof(NODE));
    new_node->value = value;
    new_node->key = key;
    return new_node;
}

NODE *get_node_pointer(LinkedList *linkedlist, void *key){

    if(linkedlist->HEAD == NULL){
        return NULL;
    }

    NODE *current = linkedlist->HEAD;

    while(current){
        if(linkedlist->equals(current->key, key)) {
            break;
        }
        else current = current->next;
    }
    return current;
};


int add_new_node(LinkedList *linkedlist, void *key, void *value){

    NODE *new_node = malloc(sizeof(NODE));
    new_node->value = value;
    new_node->key = key;
    new_node->next = linkedlist->HEAD;
    linkedlist->HEAD = new_node;
    return linkedlist->elements++;

};

void *get_node(LinkedList *linkedlist, void *node_to_search){

    NODE *current = linkedlist->HEAD;

    while(current){
        if(linkedlist->equals(current->key, node_to_search)){
            break;
        }
        current = current->next;
    }

    if(current) return current->value;
    return NULL;

};


void *remove_node(LinkedList *linkedlist, void *key){

    NODE *current = linkedlist->HEAD;
    NODE *elozo = NULL;

    while(current) {
        if(linkedlist->equals(current->key, key)){
            break;
        }
        elozo = current;
        current = current->next;
    }

    if(current){

        void * value_from_linkedlist = current->value;
        linkedlist->elements--;

        if(elozo){
            elozo->next = current->next;
        }
        else{
            linkedlist->HEAD = current->next;
        }

        free(current);

        return value_from_linkedlist;
    }

    return NULL;
};


