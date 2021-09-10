#include "dll.h"
#include <iostream>
using namespace std;

DLL::DLL(int size)
{
    capacity = size;
    // create sentinel node
    head = new DLLNode(-1);
    tail = new DLLNode(-1);
    head->next = tail;
    tail->prev = head;
}

DLL::~DLL()
{
    while (head != tail)
    {
        DLLNode *temp = head;
        head = head->next;
        delete temp;
    }
    delete tail;
}

bool DLL::empty()
{
    return head->next == tail && tail->prev == head;
}

bool DLL::full()
{
    return size == capacity;
}

Data DLL::back()
{
    if (empty())
    {
        cerr << "List is empty!\n";
        return -1;
    }
    return tail->prev->data;
}

Data DLL::front()
{
    if (empty())
    {
        cerr << "List is empty!\n";
        return -1;
    }
    return head->next->data;
}

DLLNode *DLL::push_back(int key, int val)
{
    if (full())
    {
        cerr << "List is full!\n";
        return nullptr;
    }
    DLLNode *node = new DLLNode(Data(key, val), tail->prev, tail);
    tail->prev->next = node;
    tail->prev = node;
    size++;
    return node;
}

DLLNode *DLL::push_front(int key, int val)
{
    if (full())
    {
        cerr << "List is full!\n";
        return nullptr;
    }
    DLLNode *node = new DLLNode(Data(key, val), head, head->next);
    head->next->prev = node;
    head->next = node;
    size++;
    return node;
}

Data DLL::pop_back()
{
    if (empty())
        cerr << "List is empty!\n";
    Data res = back();
    DLLNode *temp = tail->prev;
    tail->prev = temp->prev;
    temp->prev->next = tail;
    delete temp;
    size--;
    return res;
}

Data DLL::pop_front()
{
    if (empty())
        cerr << "List is empty!\n";
    Data res = front();
    DLLNode *temp = head->next;
    head->next = temp->next;
    temp->next->prev = head;
    delete temp;
    size--;
    return res;
}

void DLL::move_back(DLLNode *node)
{
    node->next->prev = node->prev;
    node->prev->next = node->next;
    node->prev = tail->prev;
    node->next = tail;
    tail->prev->next = node;
    tail->prev = node;
}