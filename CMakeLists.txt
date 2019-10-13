
cmake_minimum_required(VERSION 3.14)

project(heterogeneous-associative-lookup)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O0 -Wall -Werror -Wextra -Wpedantic")

add_compile_options(--coverage)
link_libraries(gcov)

add_executable(heterogeneous-associative-lookup main.cpp
    counter.cpp counter.h
    foo-bar.cpp foo-bar.h
    indent.cpp indent.h
    raii.cpp raii.h
)
