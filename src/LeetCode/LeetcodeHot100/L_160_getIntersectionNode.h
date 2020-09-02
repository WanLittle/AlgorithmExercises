#pragma once
#include "../../BASE.h"


class L_160_getIntersectionNode : public BASE {
public:
	virtual void main()
	{
	}
    struct ListNode {
        int val;
        ListNode *next;
        ListNode(int x) : val(x), next(NULL) {}
    };
    int length(ListNode *node)
    {
        int l = 0;
        while (node != nullptr)
        {
            ++l;
            node = node->next;
        }
        return l;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int llong = length(headA);
        int lshort = length(headB);
        ListNode *longlist, *shortlist;
        if (llong >= lshort) 
        {
            longlist = headA; shortlist = headB;
        }
        else 
        {
            longlist = headB; shortlist = headA;
            swap(llong, lshort);
        }
        for (int i = 0; i < llong - lshort; ++i)
            longlist = longlist->next;
        while (longlist != nullptr && shortlist != nullptr)
        {
            if (longlist == shortlist) return longlist;
            longlist = longlist->next;
            shortlist = shortlist->next;
        }
        return nullptr;
    }
};