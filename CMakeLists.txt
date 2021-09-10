cmake_minimum_required(VERSION 3.0.0)
project(lru-cache VERSION 0.1.0)

add_subdirectory(dll)
add_subdirectory(cache)
add_executable(lru-cache main.cpp)
target_include_directories(lru-cache PUBLIC cache)
target_link_libraries(lru-cache PUBLIC cache)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
