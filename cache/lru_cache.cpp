#include "cache.h"
#include <iostream>
using namespace std;

LRUCache::LRUCache(int size)
{
    capacity = size;
    list = new DLL(size);
}

LRUCache::~LRUCache()
{
    delete list;
}

int LRUCache::get(int key)
{
    if (empty() || map.find(key) == map.end())
    {
        cerr << "Cache miss!\n";
        return -1;
    }
    list->move_back(map[key]);
    return list->back().val;
}

void LRUCache::put(int key, int val)
{
    if (map.find(key) != map.end())
    {
        map[key]->data.val = val;
        list->move_back(map[key]);
        return;
    }
    if (full())
    {
        cerr << "Cache full- item ";
        cerr << list->front() << " evicted!\n";
        map.erase(list->pop_front().key);
        size--;
    }
    map[key] = list->push_back(key, val);
    size++;
}