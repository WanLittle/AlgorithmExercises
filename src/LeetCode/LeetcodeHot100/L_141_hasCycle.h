#pragma once
#include "../../BASE.h"


class L_141_hasCycle : public BASE {
public:
	virtual void main()
	{
	}
    struct ListNode {
        int val;
        ListNode *next;
        ListNode(int x) : val(x), next(NULL) {}
    };
    bool hasCycle(ListNode *head) {
        if (head == nullptr || head->next == nullptr) return false;
        auto fast = head->next;
        auto slow = head;
        while (fast->next && slow->next){
            fast = fast->next;
            if (fast->next == nullptr)
                return false;
            fast = fast->next;
            slow = slow->next;
            if (fast == slow)
                return true;
        }
        return false;
    }
};