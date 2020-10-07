#pragma once
#include "memory_pool.hpp"

class ClassWithMemPool
{
    static int count;
    int No;

public:
    ClassWithMemPool()
    {
        No = count;
        count++;
    }

    void print()
    {
        cout << this << ": ";
        cout << "the " << No << "th object" << endl;
    }

    void* operator new(size_t size);
    void operator delete(void* p);
    /*
    void* operator new[](size_t size);
    void operator delete[](void* p);
    */
};

//定义内存池对象
MemPool<sizeof(ClassWithMemPool), 2> mp;

void* ClassWithMemPool::operator new(size_t size)
{
    return mp.malloc();
}

void ClassWithMemPool::operator delete(void* p)
{
    mp.free(p);
}

int ClassWithMemPool::count = 0;
