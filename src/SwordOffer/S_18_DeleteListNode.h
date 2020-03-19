#pragma once
#include "../BASE.h"

// ɾ������Ľڵ�
class S_18_DeleteListNode : public BASE {
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
    ListNode* deleteNode(ListNode* head, int val) 
    {
        if (!head) return nullptr;
        if (head->val == val) 
            return head->next;
        head->next = deleteNode(head->next, val);
        return head;
    }
};