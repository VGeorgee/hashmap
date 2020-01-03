#include <stdlib.h>
#include <string.h>
#include <stdint.h>

typedef struct node
{
    void *key;
    void *value;
    struct node *next;

} NODE;

typedef struct linkedlist
{
    uint32_t elements;
    NODE *HEAD;
    NODE **Iterator;

    int (* equals)(const void *a, const void *b);
    int (* hashcode)(const void *a);
} LinkedList;


LinkedList * new_linked_list(int (* equals)(const void *a, const void*b), int (* hashcode)(const void *a));      // Initialize a LinkedList and returns its pointer
void *set_iterators(LinkedList *this_list);    //Allocates LinkedList's iterator array, and fills it with its pointers
void *get_node(LinkedList *this_list, void *key);  //returns the value of the specified String, if not found, returns NULL
int add_new_node(LinkedList *this_list, void *key,  void *value);    //adds a Node to the LinkedList in a <String int> pair
NODE *create_new_node(void *key, void *value);
NODE *get_node_pointer(LinkedList *this_list, void *key);    //returns the pointer to the Node of the specified String, if not found, returns NULL
void add_node_pointer(LinkedList *this_list, NODE *);      //adds a Node's pointer to the LinkedList
void *remove_node(LinkedList *this_list, void *key);       //removes the specified Node from the LinkedList, returning its value, if not found, returns NULL;


