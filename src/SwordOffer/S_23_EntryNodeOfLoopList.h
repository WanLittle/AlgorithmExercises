#pragma once
#include "../BASE.h"

// 链表中环的入□节点
class S_23_EntryNodeOfLoopList : public BASE {
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
    ListNode* MeetingNode(ListNode* pHead)
    {
        if (pHead == nullptr)
            return nullptr;
        ListNode *pSlow = pHead->next;
        if (pSlow == nullptr)
            return nullptr;
        ListNode* pFast = pSlow->next;
        while (pSlow != nullptr && pFast != nullptr)
        {
            if (pSlow == pFast)
                return pFast;
            pSlow = pSlow->next;
            pFast = pFast->next;
            if (pFast != nullptr)
                pFast = pFast->next;
        }
        return nullptr;
    }
    ListNode* EntryNodeOfLoop(ListNode* pHead)
    {
        if (pHead == nullptr)
            return nullptr;
        int nodesInLoop = 1;
        ListNode *meetingNode = MeetingNode(pHead);
        if (meetingNode == nullptr)
            return nullptr;
        ListNode* pNode1 = meetingNode;
        while (pNode1->next != meetingNode)
        {
            ++nodesInLoop;
            pNode1 = pNode1->next;
        }
        ListNode* pSlow = pHead;
        ListNode* pFast = pHead;
        while (nodesInLoop--)
            pFast = pFast->next;
        while (pSlow != pFast)
        {
            pSlow = pSlow->next;
            pFast = pFast->next;
        }
        return pFast;
    }
};