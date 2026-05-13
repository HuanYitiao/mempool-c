cmake_minimum_required(VERSION 3.10)
project(mempool C)

set(CMAKE_C_STANDARD 99)

add_library(mempool
    src/mempool.c
)

target_include_directories(mempool PUBLIC
    include
)

add_executable(test_mempool
    test/test_mempool.c
    test/unity.c
)

target_include_directories(test_mempool PRIVATE
    include
    test
)

target_link_libraries(test_mempool
    mempool
)


