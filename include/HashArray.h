<<<<<<< HEAD
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

    int (* equals)(const void *a, const void *b);
    int (* hashcode)(const void *a);
}Map;
#pragma pack(pop)



Map * new_map(uint32_t n, int (* equals)(const void *a, const void*b), int (* hashcode)(const void *a));

void map_put(Map *this_map, void *key, void *value);
void map_put_node(Map *this_map, NODE *);
void *map_get(Map *this_map, void *key);
NODE *map_get_node(Map *this_map, void *key);
void *map_remove(Map *this_map, void *key);
int map_contains(Map *this_map, void *key);
int map_isempty(Map *this_map);
void rehash(Map *this_map);
double get_load_factor(Map *this_map);
void print_all_nodes(Map *this_map, const char *regex);
int generate_prime(int );
=======
#include "LinkedList.h"

typedef struct map{
    LinkedList **harray;
    int tablesize;
    int elements;
    double maxloadfactor;

    int (* equals)(const void *a, const void *b);
    int (* hashcode)(const void *a);
}Map;

Map * new_map(int n, int (* equals)(const void *a, const void *b), int (* hashcode)(const void *a));


void map_put(Map *this_map, void *key, void *value);
void map_put_node(Map *this_map, NODE *);
void *map_get(Map *this_map, void *key);
NODE *map_get_node(Map *this_map, void *key);
void *map_remove(Map *this_map, void *key);
int map_contains(Map *this_map, void *key);
int map_isempty(Map *this_map);
void rehash(Map *this_map);
double get_load_factor(Map *this_map);
void print_all_nodes(Map *this_map, const char *regex);
int generate_prime(int );
>>>>>>> b60decedf32653cb10398271e26447397ba5dc38
