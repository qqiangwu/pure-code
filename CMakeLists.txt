cmake_minimum_required(VERSION 3.7)
project(pure_code)

include(conanbuildinfo.cmake)
conan_basic_setup()

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES linear/unguarded_partition.cpp linear/utils.h linear/unguarded_partition.h linear/partition.cpp linear/partition.h linear/find_kth_of_2.h linear/find_kth_of_2_test.cpp linear/find_kth.h linear/find_kth_test.cpp adt/union_find.h adt/union_find_test.cpp graph/dijkstra_sp.h graph/dijkstra_sp_test.cpp graph/floyd_sp.h graph/floyd_sp_test.cpp sort/insertion_sort.h sort/insertion_sort_test.cpp sort/bubble_sort.h sort/bubble_sort_test.cpp sort/quick_sort.h sort/quick_sort_test.cpp sort/heap_sort.h sort/heap_sort_test.cpp sort/merge_sort.h sort/merge_sort_test.cpp linear/merge_without_buffer.h linear/merge_without_buffer_test.cpp linear/merge_with_buffer.h linear/merge_with_buffer_test.cpp)
add_executable(pure_code ${SOURCE_FILES})
target_link_libraries(pure_code ${CONAN_LIBS})

add_test(pure_code_test, pure_code)