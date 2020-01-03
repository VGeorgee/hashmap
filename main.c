#include "include/HashArray.h"
#define N 1

int hashforstring(const char *s){
    int i = 0, hash = 0, g = 31;
    while(s[i]) hash = g * hash + s[i++];

    return hash & 0x7fffffff;
};

int stringequals(const void *a, const void *b){
    return strcmp(a, b) == 0;
}

int hashforintegers(int *n){
    return (*n) &0x7fffffff;
}

int integerequals(const void *a, const void *b){

    return (*(int *)a) == (*(int *)b);
}

int main()
{
    int i;

    Map *m = new_map(N, stringequals, hashforstring); // passing equals and hashcode functions for the specified data type (string in this case)

    printf("%s\n", map_isempty(m) ? "Empty Map" : "Unempty Map");

    int valuenumber = 200;

    NODE *n1 = create_new_node("HELLO WORLD", &valuenumber);
    NODE *n2 = create_new_node("anotherstring", &valuenumber);

    map_put_node(m, n1);
    map_put_node(m, n2);

    NODE *found = map_get_node(m, n1->key);

    if(found)
        printf("%d %s\n", *(int *) found->value, n1->key);

    found = map_get_node(m, "HELLO WORLD2");
    if(found)
        printf("%d %s\n", *(int *) found->value, "HELLO WORLD2");

    map_put(m, "Hello", 300);
    map_put(m, "World", 400);
    map_put(m, "iremovethis", 80000);
    printf("%s\n", map_contains(m, "Hello") ? "contains" : "not contains");
    printf("%d %s\n", (int)map_get(m, "Hello"), "Hello");

    printf("%d %s\n", (int)map_get(m, "World"), "World");
    printf("%d %s\n", (int)map_get(m, "iremovethis"), "iremovethis");

    void *removed = map_remove(m, "This is not in the map");
    printf("removed: %p\n", removed);
    removed = map_remove(m, "iremovethis");
    printf("removed: %d\n", (int)removed);
    printf("%s\n", map_isempty(m) ? "Empty Map" : "Unempty Map");



    printf("sizeof map: %d\n", sizeof(Map));
    printf("sizeof LL: %d\n", sizeof(LinkedList));
    printf("sizeof node: %d\n", sizeof(NODE));

/**


    puts("Elements in map:");
    print_all_nodes(m, "%15s %8d %2d\n");

    Map *forintegers = new_map(2, integerequals, hashforintegers);
    for(i = 0; i < 1000; i++){
        int *p = malloc(sizeof(int));
        *p = i;
        map_put(forintegers, p, 250 + i);
    }

    puts("Elements in integermap:");
    print_all_nodes(forintegers, "%4d %8d %2d\n");
    for(i = 0; i < 1000; i++){
        int *p = malloc(sizeof(int));
        *p = i;
        printf("%d\n", (int)map_get(forintegers, p));
    }
*/



    return 0;
}

