#pragma once
#include "../BASE.h"

// 输入一个链表，输出该链表中倒数第k个结点。
class S_22_FindKthOfList : public BASE {
public:
	virtual void main()
	{
	}
    struct ListNode {
        int val;
        struct ListNode *next;
        ListNode(int x) :
            val(x), next(NULL) {
        }
    };
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) 
    {
        ListNode *p = pListHead, *pre = pListHead;
        if (k == 0) return nullptr;
        if (pListHead == nullptr) return nullptr;
        for (int i = 0; i < k - 1; i++)
        {
            if (p->next == nullptr)
                return nullptr;
            p = p->next;
        }
        while (p->next != nullptr)
        {
            p = p->next;
            pre = pre->next;
        }
        return pre;
    }
};