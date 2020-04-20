#pragma once
#include "../BASE.h"

// 输入一个链表，反转链表后，输出新链表的表头。
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