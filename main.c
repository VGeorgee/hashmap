#include "HashArray.h"
#define N 1
// initial Map size

int main()
{
    int i, j;
    Map *m = initMap(N);
 




    printf("%s\n", isEmpty(m) ? "Empty Map" : "Unempty Map");

    //
    NODE n1 = {100, "HELLO WORLD", NULL};
    NODE n2 = {200, "HELLO WORLD2", NULL};
    putNode(m, &n1);
    putNode(m, &n2);
    printf("%d %s\n", getPtr(m, "HELLO WORLD")->data, "HELLO WORLD");
    printf("%d %s\n", getPtr(m, "HELLO WORLD2")->data, "HELLO WORLD2");
    //

    //
    put(m, "Hello", 300);
    put(m, "World", 400);
    put(m, "iremovethis", 80000);
    printf("%d %s\n", get(m, "Hello"), "Hello");
    printf("%d %s\n", get(m, "World"), "World");
    printf("%d %s\n", get(m, "iremovethis"), "iremovethis");
    //

    Mremove(m, "Hello World2");
    Mremove(m, "iremovethis");

    printf("%s\n", isEmpty(m) ? "Empty Map" : "Unempty Map");

    puts("Elements in map:");
    puts("");
    for(i = 0; i < m->tablesize; i++){
        if(m->harray[i]){
            getIterators(m->harray[i]);
            NODE **t = m->harray[i]->Iterator;
            for(j = 0; j < m->harray[i]->elements; j++)
                printf("%15s %8d %2d\n", t[j]->str, t[j]->data, j);
        }
    }

    return 0;
}

