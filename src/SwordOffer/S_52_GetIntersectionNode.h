#pragma once
#include "../BASE.h"

// �������������ҳ����ǵĵ�һ�������ڵ㡣
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
            node1 = node1 ? node1->next : headB; //����Ҫ��node1����nullptr�Ļ���
            node2 = node2 ? node2->next : headA;
        }
        return node1;
    }
};