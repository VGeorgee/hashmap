<div align="center">

[![Codacy Badge](https://api.codacy.com/project/badge/Grade/29bc4234414247f2beb293be419f87ba)](https://www.codacy.com/manual/VGeorgee/Hashmap-implementation-in-C?utm_source=github.com&amp;utm_medium=referral&amp;utm_content=VGeorgee/Hashmap-implementation-in-C&amp;utm_campaign=Badge_Grade)
[![Build Status](https://travis-ci.org/VGeorgee/Hashmap-implementation-in-C.svg?branch=master)](https://travis-ci.org/VGeorgee/Hashmap-implementation-in-C)
[![codecov](https://codecov.io/gh/VGeorgee/Hashmap-implementation-in-C/branch/master/graph/badge.svg)](https://codecov.io/gh/VGeorgee/Hashmap-implementation-in-C)
[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)

# Hashmap

</div>

This is an implementation of the HashMap data structure.

initialization and destruction:

`Map * new_map();`

creates a new map, returns its pointer.
   - first parameter is the initial size
   - second parameter is the function to compare keys
   - third parameter is the function to generate hashes for keys


`void delete_map();`

deletes the map

---

working with a map:
the following functions first parameter is always the pointer to an initialized
map.

`void map_put();`

creates a new entry in the map
  - second parameter is the key
  - third parameter is the value

returns nothing.


`void *map_get();`

gets the value from an entry
   - second parameter is the key of an entry
   
returns `NULL` if entry not found for key


`void *map_remove();`

removes an entry from the map
   - second parameter is the key of an entry
   
returns the value of the entry after remove,
returns `NULL` if entry not found.

`int map_contains();`
returns if an entry was found for the given key.
   - second parameter is the key of an entry
   
returns true if an entry was found, false otherwise.


`int map_isempty();`

returns true if the given map is empty, returns false if not.

---

usage:

the following example uses strings as key and value
```
#include "HashArray.h"

int strhash(char *str){
    int hash = 1, i;
    for(i = 0; s[i]; i++){
        hash = (hash * 10) + s[i];
    }
    return hash;
}


int main(){
    Map *mymap = new_map(10, strcmp, strhash);
    printf("is the map empty? -%s", map_isempty(mymap) ? "yes" : "no");
   
    //put an element in the map:
    map_put(mymap, "key", "value");
    printf("%s\n", map_get("key"));    
    printf("is the map empty? -%s", map_isempty(mymap) ? "yes" : "no");        
    map_remove(mymap, "key");
    printf("%s\n", map_get("key"));
    printf("is the map empty? -%s", map_isempty(mymap) ? "yes" : "no");
    return 0;
}
```