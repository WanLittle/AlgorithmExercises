#pragma once
#include "../BASE.h"

// ����һ��������ת��������������ı�ͷ��
class S_24_ReverseList : public BASE {
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
    ListNode* reverseList(ListNode* head)
    {
        ListNode *p = head, *pre = nullptr, *next = nullptr;
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