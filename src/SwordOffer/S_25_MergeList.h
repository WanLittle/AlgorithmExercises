#pragma once
#include "../BASE.h"

// �ϲ��������������  
class S_25_MergeList : public BASE {
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
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
        if (pHead1 == nullptr)
            return pHead2;
        if (pHead2 == nullptr)
            return pHead1;
        ListNode* head;
        if (pHead1->val <= pHead2->val)
        {
            head = pHead1;
            head->next = Merge(pHead1->next, pHead2);
        }
        else
        {
            head = pHead2;
            head->next = Merge(pHead1, pHead2->next);
        }
        return head;
    }
};