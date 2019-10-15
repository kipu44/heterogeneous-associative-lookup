
cmake_minimum_required(VERSION 3.14)

project(heterogeneous-associative-lookup)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O0 -Wall -Werror -Wextra -Wpedantic")

if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
    add_compile_options(-fprofile-instr-generate -fcoverage-mapping)
    add_link_options(-fprofile-instr-generate)
    #Uncomment in case of linker errors
    #link_libraries(clang_rt.profile-x86_64)
elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
    add_compile_options(--coverage)
    link_libraries(gcov)
endif ()

add_executable(heterogeneous-associative-lookup main.cpp
    comparators.cpp comparators.h
    counter.cpp counter.h
    foo-bar.cpp foo-bar.h
    indent.cpp indent.h
    raii.cpp raii.h
)
