#include "HashArray.h"
#define NextNPrime 5
#define MAXLOADFACTOR 0.75

Map * initMap(int n)
{
    int i;
    Map *newmap = malloc(sizeof(Map));
    newmap->harray = malloc(sizeof(LinkedList *) * n);
    for(i = 0; i < n; i++)
        newmap->harray[i] = initLL();
    newmap->tablesize = n;
    newmap->maxloadfactor = MAXLOADFACTOR;
    newmap->elements = 0;

    return newmap;
};

int getHash(char *s)
{
    int i = 0, hash = 0, g = 31;
    while(s[i]) hash = g * hash + s[i++];

    return hash & 0x7fffffff;
};

void put(Map *thism, char *s, int n)
{

    if(getLoadFactor(thism) >= thism->maxloadfactor)
        reHash(thism);

    int hash = getHash(s);
    hash %= thism->tablesize;
    addNode(thism->harray[hash], s, n);
    thism->elements++;

};

void putNode(Map *thism, NODE *np){


    if(getLoadFactor(thism) >= thism->maxloadfactor)
        reHash(thism);

    int hash = getHash(np->str);
    hash %= thism->tablesize;
    addNodePointer(thism->harray[hash], np);
    thism->elements++;
}



int get(Map *thism, char *s)
{
    return getNode(thism->harray[getHash(s) % thism->tablesize], s);
};

NODE *getPtr(Map *thism, char *s){

    return getNodePointer(thism->harray[getHash(s) % thism->tablesize], s);
}

int Mremove(Map *thism, char *s)
{
    int ret = removeNode(thism->harray[getHash(s) % thism->tablesize], s);
    if(ret != -1)
        thism->elements--;
    return ret;
}

int contains(Map *thism, char *s)
{
    return getNode(thism->harray[getHash(s) % thism->tablesize], s) == -1 ? 0 : 1;
};

int isEmpty(Map *thism)
{
    return thism->elements == 0;
};


void reHash(Map *thism)
{
    int i, nextprime = genPrime(thism->tablesize);

    LinkedList **newLL = malloc(sizeof(LinkedList *) * nextprime);

    for(i = 0; i < nextprime; i++)
        newLL[i] = initLL();

    for(i = 0; i < thism->tablesize; i++)
    {
        NODE *f = thism->harray[i]->HEAD;
        while(f != NULL)
        {
            addNodePointer(newLL[getHash(f->str) % nextprime], f);
            NODE *elozo = f;
            f = f->next;
            elozo->next = NULL;
        }
        free(thism->harray[i]);
    }

    thism->tablesize = nextprime;
    thism->harray = newLL;

};

double getLoadFactor(Map *thism)
{
    if(thism->elements)
        return (double)thism->elements / thism->tablesize;

    return 0.0;
};

int isPrime(int n)
{
    int i;
    for(i = 2; i <= n/2; i++)
    {
        if(n % i == 0)
            return 0;
    }
    return 1;
};

int genPrime(int n)
{
    int k = 0, np = n;
    while(k < NextNPrime)
    {
        if(isPrime(++np))
            k++;
    }
    return np;
};
