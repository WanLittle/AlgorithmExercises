#include <iostream>
using namespace std;

template<int ObjectSize, int NumofObjects = 20>
class MemPool
{
private:
    //空闲节点结构体
    struct FreeNode
    {
        FreeNode* pNext;
        char data[ObjectSize];
    };

    //内存块结构体
    struct MemBlock
    {
        MemBlock* pNext;
        FreeNode data[NumofObjects];
    };

    FreeNode* freeNodeHeader;
    MemBlock* memBlockHeader;

public:
    MemPool()
    {
        freeNodeHeader = NULL;
        memBlockHeader = NULL;
    }

    ~MemPool()
    {
        MemBlock* ptr;
        while (memBlockHeader)
        {
            ptr = memBlockHeader->pNext;
            delete memBlockHeader;
            memBlockHeader = ptr;
        }
    }
    void* malloc();
    void free(void*);
};

//分配空闲的节点
template<int ObjectSize, int NumofObjects>
void* MemPool<ObjectSize, NumofObjects>::malloc()
{
    //无空闲节点，申请新内存块
    if (freeNodeHeader == NULL)
    {
        MemBlock* newBlock = new MemBlock;
        newBlock->pNext = NULL;

        freeNodeHeader = &newBlock->data[0];	 //设置内存块的第一个节点为空闲节点链表的首节点
        //将内存块的其它节点串起来
        for (int i = 1; i < NumofObjects; ++i)
        {
            newBlock->data[i - 1].pNext = &newBlock->data[i];
        }
        newBlock->data[NumofObjects - 1].pNext = NULL;

        //首次申请内存块
        if (memBlockHeader == NULL)
        {
            memBlockHeader = newBlock;
        }
        else
        {
            //将新内存块加入到内存块链表
            newBlock->pNext = memBlockHeader;
            memBlockHeader = newBlock;
        }
    }
    //返回空节点闲链表的第一个节点
    void* freeNode = freeNodeHeader;
    freeNodeHeader = freeNodeHeader->pNext;
    return freeNode;
}

//释放已经分配的节点
template<int ObjectSize, int NumofObjects>
void MemPool<ObjectSize, NumofObjects>::free(void* p)
{
    FreeNode* pNode = (FreeNode*)p;
    pNode->pNext = freeNodeHeader;	//将释放的节点插入空闲节点头部
    freeNodeHeader = pNode;
}