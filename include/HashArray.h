#include "LinkedList.h"

typedef struct map{
    LinkedList **harray;
    int tablesize;
    int elements;
    double maxloadfactor;

    int (* equals)(const void *a, const void *b);
    int (* hashcode)(const void *a);
}Map;


Map * new_map();

//
int getHash(void *);
//

void map_put(Map *this_map, void *key, void *value);
void map_put_node(Map *this_map, NODE *);
void *map_get(Map *this_map, void *key);
NODE *map_get_node(Map *this_map, void *key);
int map_remove(Map *this_map, void *key);
int map_contains(Map *this_map, void *key);
int map_isempty(Map *this_map);
void rehash(Map *this_map);
double get_load_factor(Map *this_map);
int generate_prime(int );
