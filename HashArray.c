#include "HashArray.h"
#define NextNPrime 5
#define MAXLOADFACTOR 0.75

Map * new_map(int n, int (* eq)(const void *a, const void*b), int (* hash)(const void *a))
{
    int i;
    Map *new_map = malloc(sizeof(Map));
    new_map->harray = malloc(sizeof(LinkedList *) * n);

    for(i = 0; i < n; i++){
        new_map->harray[i] = initLL();
    }
    new_map->tablesize = n;
    new_map->maxloadfactor = MAXLOADFACTOR;
    new_map->elements = 0;

    new_map->equals = eq;
    new_map->hashcode = hash;
    
    return new_map;
};

///
int getHash(char *s)
{
    int i = 0, hash = 0, g = 31;
    while(s[i]) hash = g * hash + s[i++];

    return hash & 0x7fffffff;
};
///



void map_put(Map *this_map, void *key, void *value)
{

    if(getLoadFactor(this_map) >= this_map->maxloadfactor)
        reHash(this_map);

    int hash = this_map->hashcode(key);
    hash %= this_map->tablesize;
    add_new_node(this_map->harray[hash], key, value);
    this_map->elements++;

};

void map_put_node(Map *this_map, NODE *np){


    if(getLoadFactor(this_map) >= this_map->maxloadfactor)
        reHash(this_map);

    int hash = this_map->hashcode(np->str);
    hash %= this_map->tablesize;
    addNodePointer(this_map->harray[hash], np);
    this_map->elements++;
}



int map_get(Map *this_map, char *s)
{
    return getNode(this_map->harray[this_map->hashcode(s) % this_map->tablesize], s);
};

NODE *getPtr(Map *this_map, char *s){

    return getNodePointer(this_map->harray[this_map->hashcode(s) % this_map->tablesize], s);
}

int map_remove(Map *this_map, char *s)
{
    int ret = removeNode(this_map->harray[this_map->hashcode(s) % this_map->tablesize], s);
    if(ret != -1)
        this_map->elements--;
    return ret;
}

int map_contains(Map *this_map, char *s)
{
    return map_get_node(this_map->harray[this_map->hashcode(s) % this_map->tablesize], s) == -1 ? 0 : 1;
};

int map_isempty(Map *this_map)
{
    return this_map->elements == 0;
};


void map_re_hash(Map *this_map)
{
    int i, nextprime = genPrime(this_map->tablesize);

    LinkedList **newLL = malloc(sizeof(LinkedList *) * nextprime);

    for(i = 0; i < nextprime; i++)
        newLL[i] = initLL();

    for(i = 0; i < this_map->tablesize; i++)
    {
        NODE *f = this_map->harray[i]->HEAD;
        while(f != NULL)
        {
            addNodePointer(newLL[this_map->hashcode(f->str) % nextprime], f);
            NODE *elozo = f;
            f = f->next;
            elozo->next = NULL;
        }
        free(this_map->harray[i]);
    }

    this_map->tablesize = nextprime;
    this_map->harray = newLL;

};

double  get_load_factor(Map *this_map)
{
    if(this_map->elements)
        return (double)this_map->elements / this_map->tablesize;

    return 0.0;
};

int is_prime(int n)
{
    int i;
    for(i = 2; i <= n/2; i++)
    {
        if(n % i == 0)
            return 0;
    }
    return 1;
};

int generate_prime(int n)
{
    int k = 0, np = n;
    while(k < NextNPrime)
    {
        if(is_prime(++np))
            k++;
    }
    return np;
};
