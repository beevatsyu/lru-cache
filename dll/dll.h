#if !defined(DLL_H)
#define DLL_H
#include <ostream>

struct Data
{
    int key;
    int val;
    Data(int key = 0, int val = 0)
    {
        this->key = key;
        this->val = val;
    }

    friend std::ostream &operator<<(std::ostream &os, Data d)
    {
        return os << "(" << d.key << ", " << d.val << ")";
    }
};

struct DLLNode
{
    Data data;
    DLLNode *prev;
    DLLNode *next;

    DLLNode(Data data = Data(), DLLNode *prev = nullptr, DLLNode *next = nullptr)
    {
        this->data = data;
        this->prev = prev;
        this->next = next;
    }
};

class DLL
{
private:
    DLLNode *head;
    DLLNode *tail;
    int capacity;

public:
    int size;
    DLL(int);
    ~DLL();
    Data front();
    Data back();
    bool empty();
    bool full();
    DLLNode *push_back(int, int);
    DLLNode *push_front(int, int);
    Data pop_back();
    Data pop_front();
    void move_back(DLLNode *);
};

#endif // DLL_H
