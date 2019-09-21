#include "include/HashArray.h"
#define N 1
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
    Map *m = new_map(N, &stringequals, &hashforstring);

    printf("%s\n", map_isempty(m) ? "Empty Map" : "Unempty Map");
    puts("HENLO");
    //
    NODE n1 = {value: 100, key: "HELLO WORLD", NULL};
    NODE n2 = {value:200, key: "HELLO WORLD2", NULL};

    map_put_node(m, &n1);
    return 0;
    map_put_node(m, &n2);
    printf("%d %s\n", map_get_node(m, "HELLO WORLD")->value, "HELLO WORLD");
    printf("%d %s\n", map_get_node(m, "HELLO WORLD2")->value, "HELLO WORLD2");
    //

    //
    map_put(m, "Hello", 300);
    map_put(m, "World", 400);
    map_put(m, "iremovethis", 80000);
    printf("%d %s\n", map_get(m, "Hello"), "Hello");
    printf("%d %s\n", map_get(m, "World"), "World");
    printf("%d %s\n", map_get(m, "iremovethis"), "iremovethis");
    //

    map_remove(m, "Hello World2");
    map_remove(m, "iremovethis");

    printf("%s\n", map_isempty(m) ? "Empty Map" : "Unempty Map");

    puts("Elements in map:");
    puts("");
    for(i = 0; i < m->tablesize; i++){
        if(m->harray[i]){
            get_iterators(m->harray[i]);
            NODE **t = m->harray[i]->Iterator;
            for(j = 0; j < m->harray[i]->elements; j++)
                printf("%15s %8d %2d\n", t[j]->key, t[j]->value, j);
        }
    }

    return 0;
    return 0;
}

