#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include "LinkedList.h"

#pragma pack(push, 2)
typedef struct map{
    LinkedList **harray;
    uint32_t tablesize;
    uint32_t elements;
    double maxloadfactor;
    NODE **iterator;

    int (* equals)(const void *a, const void *b);
    int (* hashcode)(const void *a);
}Map;
#pragma pack(pop)



Map * new_map(int n, int (* equals)(const void *a, const void*b), int (* hashcode)(const void *a));
void delete_map(Map *this_map);

void map_put(Map *this_map, void *key, void *value);
void map_put_node(Map *this_map, NODE *);
void *map_get(Map *this_map, void *key);
NODE *map_get_node(Map *this_map, void *key);
void *map_remove(Map *this_map, void *key);
int map_contains(Map *this_map, void *key);
int map_isempty(Map *this_map);
NODE **iterator(Map *this_map);
static void rehash(Map *this_map);
static double get_load_factor(Map *this_map);
static int generate_prime(int );
