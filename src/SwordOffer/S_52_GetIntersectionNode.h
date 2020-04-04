#pragma once
#include "../BASE.h"

// 输入两个链表，找出它们的第一个公共节点。
class S_52_GetIntersectionNode : public BASE {
public:
	virtual void main()
	{
	}
    struct ListNode {
        int val;
        ListNode *next;
        ListNode(int x) : val(x), next(NULL) {}
        
    };
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        ListNode *node1 = headA;
        ListNode *node2 = headB;
        while (node1 != node2)
        {
            node1 = node1 ? node1->next : headB; //必须要给node1等于nullptr的机会
            node2 = node2 ? node2->next : headA;
        }
        return node1;
    }
};