#include <stdio.h>
#include "HashArray.h"
#define N 1

int hashforstring(const void *s){
    char *t = (char *)s;
    int i = 0, hash = 0, g = 31;
    while(t[i]) hash = g * hash + t[i++];

    return hash & 0x7fffffff;
};

int stringequals(const void *a, const void *b){
    return strcmp(a, b) == 0;
}

int hashforintegers(const void *n){
    int *num = (int *)n;
    return (*num) &0x7fffffff;
}

int integerequals(const void *a, const void *b){

    return (*(int *)a) == (*(int *)b);
}

int main()
{
    int i;

    delete_map( new_map(-1, stringequals, hashforstring));
    delete_map( new_map(-2, stringequals, hashforstring));
    delete_map( new_map(0, stringequals, hashforstring));
    delete_map( new_map(1, stringequals, hashforstring));

    Map *m = new_map(N, stringequals, hashforstring); // passing equals and hashcode functions for the specified data type (string in this case)

    printf("%s\n", map_isempty(m) ? "Empty Map" : "Unempty Map");

    int valuenumber = 200;

    NODE *n1 = create_new_node("HELLO WORLD", &valuenumber);
    NODE *n2 = create_new_node("anotherstring", &valuenumber);

    map_put_node(m, n1);
    map_put_node(m, n2);

    NODE *found = map_get_node(m, n1->key);
    if(found)
        printf("%d %s\n", *(int *) found->value, (char *) n1->key);

    found = map_get_node(m, "HELLO WORLD2");
    if(found)
        printf("%d %s\n", *(int *) found->value, "HELLO WORLD2");

    map_put(m, "Hello", (void *) 300);
    map_put(m, "World", (void *) 400);
    map_put(m, "iremovethis", (void *) 80000);
    printf("%s\n", map_contains(m, "Hello") ? "contains" : "not contains");
    printf("%p %s\n", map_get(m, "Hello"), "Hello");

    printf("%p %s\n", map_get(m, "World"), "World");
    printf("%p %s\n", map_get(m, "iremovethis"), "iremovethis");

    void *removed = map_remove(m, "This is not in the map");
    printf("removed: %p\n", removed);
    removed = map_remove(m, "iremovethis");
    printf("removed: %p\n", removed);
    printf("%s\n", map_isempty(m) ? "Empty Map" : "Unempty Map");

    puts("Elements in map:");

    Map *forintegers = new_map(2, integerequals, hashforintegers);
    for(i = 250; i < 1250; i++){
        int *p = malloc(sizeof(int));
        *p = i;
        map_put(forintegers, p, (void *)i);
    }

    puts("Elements in integermap:");
    for(i = 0; i < 1000; i++){
        int *p = malloc(sizeof(int));
        *p = i;
        printf("%p\n", map_get(forintegers, p));
    }

    return 0;
}


/*

add_executable(Hashmap_implementation_in_C
        include/HashArray.h
        include/LinkedList.h
        src/HashArray.c
        src/LinkedList.c
        test.c)

 */
