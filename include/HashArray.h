#include "LinkedList.h"

typedef struct map{
    LinkedList **harray;
    int tablesize;
    int elements;
    double maxloadfactor;
}Map;

Map * initMap();
int getHash(char *);
void put(Map *, char *, int);
void putNode(Map *, NODE *);
int get(Map *, char *);
NODE *getPtr(Map *, char *);
int Mremove(Map *, char *);
int contains(Map *thism, char *s);
int isEmpty(Map *);
void reHash(Map *);
double getLoadFactor(Map *);
int genPrime(int );
