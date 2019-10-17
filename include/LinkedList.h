#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    void *key;
    void *value;
    struct node *next;
    
} NODE;

typedef struct linkedlist
{
    NODE *HEAD;
    NODE **Iterator;
    int elements;

    int (* equals)(const void *a, const void *b);
    int (* hashcode)(const void *a);
} LinkedList;



LinkedList * new_linked_list();      // Initialize a LinkedList and returns its pointer
void get_iterators(LinkedList *);    //Allocates LinkedList's iterator array, and fills it with its pointers
void *get_node(LinkedList *, void *);  //returns the value of the specified String, if not found, returns NULL
int add_new_node(LinkedList *, void *,  void *);    //adds a Node to the LinkedList in a <String int> pair
NODE *create_new_node(void *key, void *value);
NODE *get_node_pointer(LinkedList *, void *);    //returns the pointer to the Node of the specified String, if not found, returns NULL
void add_node_pointer(LinkedList *, NODE *);      //adds a Node's pointer to the LinkedList
void *remove_node(LinkedList *, void *);       //removes the specified Node from the LinkedList, returning its value, if not found, returns NULL;


