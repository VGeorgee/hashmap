#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    void *key;
    void *value;

//
    char *str;
    int data;
//

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



LinkedList * initLL();      // Initialize a LinkedList and returns its pointer

void getIterators(LinkedList *);    //Allocates LinkedList's iterator array, and fills it with its pointers

void *getNode(LinkedList *, char *);  //returns the value of the specified String, if not found, returns NULL
int addNode(LinkedList *, char *,  int);    //adds a Node to the LinkedList in a <String int> pair

NODE *getNodePointer(LinkedList *, char *);    //returns the pointer to the Node of the specified String, if not found, returns NULL
void addNodePointer(LinkedList *, NODE *);      //adds a Node's pointer to the LinkedList

void *removeNode(LinkedList *, char *);       //removes the specified Node from the LinkedList, returning its value, if not found, returns NULL;


