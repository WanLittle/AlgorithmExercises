#include <iostream>
using namespace std;

template<int ObjectSize, int NumofObjects = 20>
class MemPool
{
private:
    //���нڵ�ṹ��
    struct FreeNode
    {
        FreeNode* pNext;
        char data[ObjectSize];
    };

    //�ڴ��ṹ��
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

//������еĽڵ�
template<int ObjectSize, int NumofObjects>
void* MemPool<ObjectSize, NumofObjects>::malloc()
{
    //�޿��нڵ㣬�������ڴ��
    if (freeNodeHeader == NULL)
    {
        MemBlock* newBlock = new MemBlock;
        newBlock->pNext = NULL;

        freeNodeHeader = &newBlock->data[0];	 //�����ڴ��ĵ�һ���ڵ�Ϊ���нڵ�������׽ڵ�
        //���ڴ��������ڵ㴮����
        for (int i = 1; i < NumofObjects; ++i)
        {
            newBlock->data[i - 1].pNext = &newBlock->data[i];
        }
        newBlock->data[NumofObjects - 1].pNext = NULL;

        //�״������ڴ��
        if (memBlockHeader == NULL)
        {
            memBlockHeader = newBlock;
        }
        else
        {
            //�����ڴ����뵽�ڴ������
            newBlock->pNext = memBlockHeader;
            memBlockHeader = newBlock;
        }
    }
    //���ؿսڵ�������ĵ�һ���ڵ�
    void* freeNode = freeNodeHeader;
    freeNodeHeader = freeNodeHeader->pNext;
    return freeNode;
}

//�ͷ��Ѿ�����Ľڵ�
template<int ObjectSize, int NumofObjects>
void MemPool<ObjectSize, NumofObjects>::free(void* p)
{
    FreeNode* pNode = (FreeNode*)p;
    pNode->pNext = freeNodeHeader;	//���ͷŵĽڵ������нڵ�ͷ��
    freeNodeHeader = pNode;
}