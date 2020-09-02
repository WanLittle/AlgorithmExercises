#pragma once
#include "../../BASE.h"


class L_19_removeNthFromEnd : public BASE {
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp = new ListNode(0);
        temp->next = head;
        auto left = temp, right = temp;
        for (int i = 1; i <= n + 1; ++i)
        {
            right = right->next;
        }
        while (right != nullptr)
        {
            left = left->next;
            right = right->next;
        }
        left->next = left->next->next;
        auto result = temp->next;
        delete temp;
        return result;
    }
};