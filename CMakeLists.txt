cmake_minimum_required(VERSION 3.15)
project(Hashmap_implementation_in_C C)

set(CMAKE_C_STANDARD 11)

include_directories(include)


add_library(hashmap include/HashArray.h
        include/LinkedList.h
        src/HashArray.c
        src/LinkedList.c)
