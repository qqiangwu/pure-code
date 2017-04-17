cmake_minimum_required(VERSION 3.7)
project(pure_code)

include(conanbuildinfo.cmake)
conan_basic_setup()

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES linear/unguarded_partition.cpp linear/utils.h linear/unguarded_partition.h linear/partition.cpp linear/partition.h)
add_executable(pure_code ${SOURCE_FILES})
target_link_libraries(pure_code ${CONAN_LIBS})

add_test(pure_code_test, pure_code)