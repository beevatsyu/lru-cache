#include <iostream>
#include "cache.h"
using namespace std;
// Drive program to test out our LRU Cache implementation
int main(int argc, char const *argv[])
{
    Cache *cache = new LRUCache(4);
    cout << cache->get(1) << endl; // cache miss, due to empty
    cache->put(1, 11);
    cache->put(2, 22);
    cache->put(3, 33);
    cout << cache->get(2) << endl;
    cache->put(4, 44);
    cache->put(1, 111); // cache update 1
    cache->put(5, 55); // cache full, 3 evicted as per LRU
    cout << cache->get(3) << endl; // cache miss
    delete cache;
    return 0;
}
