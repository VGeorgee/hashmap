#include "LinkedList.h"

LinkedList *new_linked_list(int (* equals)(const void *a, const void*b), int (* hashcode)(const void *a)){
    LinkedList *linked_list = malloc(sizeof(LinkedList));
    linked_list->elements = 0;
    linked_list->HEAD = NULL;
    linked_list->equals = equals;
    return linked_list;
};

void add_node_pointer(LinkedList *this_list, NODE *np){
    np->next = this_list->HEAD;
    this_list->HEAD = np;
    this_list->elements++;
};

NODE *create_new_node(void *key, void *value){
    NODE *new_node = malloc(sizeof(NODE));
    new_node->value = value;
    new_node->key = key;
    return new_node;
}

NODE *get_node_pointer(LinkedList *this_list, void *key){

    if(this_list->HEAD == NULL){
        return NULL;
    }

    NODE *current = this_list->HEAD;

    while(current){
        if(this_list->equals(current->key, key)) {
            break;
        }
        else current = current->next;
    }
    return current;
};


void *get_node(LinkedList *this_list, void *node_to_search){

    NODE *current = this_list->HEAD;

    while(current){
        if(this_list->equals(current->key, node_to_search)){
            break;
        }
        current = current->next;
    }

    if(current) return current->value;
    return NULL;

};


void *remove_node(LinkedList *this_list, void *key){

    NODE *current = this_list->HEAD;
    NODE *elozo = NULL;

    while(current) {
        if(this_list->equals(current->key, key)){
            break;
        }
        elozo = current;
        current = current->next;
    }

    if(current){

        void * value_from_linkedlist = current->value;
        this_list->elements--;

        if(elozo){
            elozo->next = current->next;
        }
        else{
            this_list->HEAD = current->next;
        }

        free(current);

        return value_from_linkedlist;
    }

    return NULL;
};
