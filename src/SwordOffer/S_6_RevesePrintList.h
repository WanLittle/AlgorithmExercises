#pragma once
#include "../BASE.h"

class S_6_RevesePrintList : public BASE {
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
    vector<int> printListFromTailToHead(ListNode* head) {
        vector<int> result;
        if (head == NULL)
            return result;
        stack<int> s;
        while (head != NULL)
        {
            s.push(head->val);
            head = head->next;
        }
        while (!s.empty())
        {
            result.push_back(s.top());
            s.pop();
        }
        return result;
    }
};