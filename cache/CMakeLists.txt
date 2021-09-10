add_library(cache lru_cache.cpp)
target_include_directories(cache PUBLIC dll)
target_link_libraries(cache PUBLIC dll)