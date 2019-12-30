#include "include/HashArray.h"
#define NextNPrime 5
#define MAXLOADFACTOR 0.75

Map * new_map(int n, int (* equals)(const void *a, const void *b), int (* hashcode)(const void *a))
{
    if(n <= 0){
        n = 10;
    }
    int i;
    Map *new_map = malloc(sizeof(Map));
    new_map->harray = malloc(sizeof(LinkedList *) * n);

    for(i = 0; i < n; i++){
        new_map->harray[i] = new_linked_list(equals, hashcode);
    }
    new_map->tablesize = n;
    new_map->maxloadfactor = MAXLOADFACTOR;
    new_map->elements = 0;

    new_map->equals = equals;
    new_map->hashcode = hashcode;

    return new_map;
};


void map_put(Map *this_map, void *key, void *value)
{

    NODE *new_node = create_new_node(key, value);
    map_put_node(this_map, new_node);

};


void map_put_node(Map *this_map, NODE *node_pointer){

    if(get_load_factor(this_map) >= this_map->maxloadfactor)
        rehash(this_map);

    int hash = this_map->hashcode(node_pointer->key);

    hash %= this_map->tablesize;
    add_node_pointer(this_map->harray[hash], node_pointer);

    this_map->elements++;
};


void *map_get(Map *this_map, void *key){
    return get_node(this_map->harray[this_map->hashcode(key) % this_map->tablesize], key);
};


NODE *map_get_node(Map *this_map, void *key){
    return get_node_pointer(this_map->harray[this_map->hashcode(key) % this_map->tablesize], key);
};


void *map_remove(Map *this_map, void *key){
    void *removed_element = remove_node(this_map->harray[this_map->hashcode(key) % this_map->tablesize], key);

    if(removed_element != NULL)
        this_map->elements--;

    return removed_element;
};


int map_contains(Map *this_map, void *key){
    return map_get_node(this_map, key) == -1 ? 0 : 1;
};


int map_isempty(Map *this_map){
    return this_map->elements == 0;
};


void rehash(Map *this_map){
    int i, next_size = generate_prime(this_map->tablesize);
    LinkedList **newLL = malloc(sizeof(LinkedList *) * next_size);

    for(i = 0; i < next_size; i++){
        newLL[i] = new_linked_list(this_map->equals, this_map->hashcode);
    }

    for(i = 0; i < this_map->tablesize; i++)
    {
        NODE *node = this_map->harray[i]->HEAD;
        if(node){
            while(node != NULL)
            {
                add_node_pointer(newLL[this_map->hashcode(node->key) % next_size], node);
                NODE *elozo = node;
                node = node->next;
                elozo->next = NULL;
            }
            free(this_map->harray[i]);
            this_map->harray[i] = NULL;
        }
    }
    this_map->tablesize = next_size;
    this_map->harray = newLL;
};


double  get_load_factor(Map *this_map){
    if(this_map->elements > 0)
        return (double)this_map->elements / this_map->tablesize;

    return 0.0;
};


void print_all_nodes(Map *this_map, const char *regex){
    for(int i = 0; i < this_map->tablesize; i++){
        if(this_map->harray[i]){
            NODE **t = set_iterators(this_map->harray[i]);
            for(int j = 0; j < this_map->harray[i]->elements; j++){
                printf(regex, t[j]->key, t[j]->value, j);
            }
        }
    }
}


int is_prime(int n){
    int i;
    for(i = 2; i <= n/2; i++)
    {
        if(n % i == 0)
            return 0;
    }
    return 1;
};

int generate_prime(int n){
    int k = 0, np = n;
    while(k < NextNPrime)
    {
        if(is_prime(++np))
            k++;
    }
    return np;
};
