#if !defined(CACHE_H)
#define CACHE_H
#include "../dll/dll.h"
#include <unordered_map>

class Cache
{
protected:
    int capacity;
    virtual bool empty() { return size == 0; }
    virtual bool full() { return size == capacity; }

public:
    int size;
    virtual int get(int) = 0;
    virtual void put(int, int) = 0;
};

class LRUCache : public Cache
{
protected:
    DLL *list;
    std::unordered_map<int, DLLNode *> map;

public:
    LRUCache(int);
    ~LRUCache();
    int get(int);
    void put(int, int);
};

#endif // CACHE_H
