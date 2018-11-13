#include "LinkedList.h"

LinkedList *initLL(){
    LinkedList *nn = malloc(sizeof(LinkedList));
    nn->elements = 0;
    nn->HEAD = NULL;
    nn->Iterator = NULL;
    return nn;
};

void getIterators(LinkedList *ll){
    if(ll->HEAD){

    free(ll->Iterator);
    NODE **n = malloc(sizeof(NODE *) * ll->elements);
    NODE *p = ll->HEAD;

    int i;
    for(i = 0; p; p = p->next) n[i++] = p;
    ll->Iterator = n;
    }
}



void addNodePointer(LinkedList *ll, NODE *np){
    np->next = ll->HEAD;
    ll->HEAD = np;
    ll->elements++;
};

NODE * getNodePointer(LinkedList *ll, char *s)
{

    NODE *f = ll->HEAD;
    while(f && strcmp(f->str, s)) f = f->next;
    return f;

};

int addNode(LinkedList *ll, char *s, int n){

    NODE *neww = malloc(sizeof(NODE));
    neww->data = n;
    neww->str = s;
    neww->next = ll->HEAD;
    ll->HEAD = neww;
    return ll->elements++;

};

int getNode(LinkedList *ll, char *s){

    NODE *f = ll->HEAD;
    while(f && strcmp(f->str, s)) f = f->next;

    if(f) return f->data;
    return -1;

};


int removeNode(LinkedList *ll, char *s){

    int dt;
    NODE *f = ll->HEAD;
    NODE *elozo = NULL;

    while(f && strcmp(f->str, s)) {
            elozo = f;
            f = f->next;
    }

    if(f){

        dt = f->data;
        ll->elements--;

        if(elozo) elozo->next = f->next;
        else ll->HEAD = f->next;

        free(f);
        return dt;
    }

    return -1;
};


