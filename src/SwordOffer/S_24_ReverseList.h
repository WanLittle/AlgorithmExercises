#pragma once
#include "../BASE.h"

// ����һ��������ת��������������ı�ͷ��
class S_24 : public BASE {
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
    ListNode* ReverseList(ListNode* pHead)
    {
        ListNode *p = pHead, *pre = nullptr, *next = nullptr, *head = nullptr;
        while (p != nullptr)
        {
            next = p->next;
            if (next == nullptr)
                head = p;
            p->next = pre;
            pre = p;
            p = next;
        }
        return head;
    }
};