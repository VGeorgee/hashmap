#include "include/HashArray.h"
#define N 100
// initial Map size


int hashforstring(char *s){
    int i = 0, hash = 0, g = 31;
    while(s[i]) hash = g * hash + s[i++];

    return hash & 0x7fffffff;
};

int stringequals(const void *a, const void *b){
    return strcmp(a, b) == 0;
}


int main()
{
    int i, j;
    Map *m = new_map(N, stringequals, hashforstring); // passing equals and hashcode functions for the specified data type (string in this case)

    printf("%s\n", map_isempty(m) ? "Empty Map" : "Unempty Map");

    int valuenumber = 200;
    char *mykey = "ASDASDASD";

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

    //

    //
    map_put(m, "Hello", 300);
    map_put(m, "World", 400);
    map_put(m, "iremovethis", 80000);

    printf("%d %s\n", map_get(m, "Hello"), "Hello");

    printf("%d %s\n", map_get(m, "World"), "World");
    printf("%d %s\n", map_get(m, "iremovethis"), "iremovethis");
    //

    void *removed = map_remove(m, "This is not in the map");
    printf("removed: %p\n", removed);
    removed = map_remove(m, "iremovethis");
    printf("removed: %d\n", removed);

    printf("%s\n", map_isempty(m) ? "Empty Map" : "Unempty Map");


    puts("Elements in map:");
    print_all_nodes(m);

    return 0;
}

