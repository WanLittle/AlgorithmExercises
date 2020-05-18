#pragma once
#include "../BASE.h"

class S_35_CopyRandomList : public BASE {
public:
	virtual void main()
	{
	}
    class Node {
    public:
        int val;
        Node* next;
        Node* random;

        Node(int _val) {
            val = _val;
            next = nullptr;
            random = nullptr;
        }
    };
    Node* copyRandomList(Node* head) 
    {
        if (head == nullptr) return head;

        unordered_map<Node*, Node*> rnd;

        Node* fakeHead = new Node(head->val);

        Node* p = head;
        Node* fp = fakeHead;

        while (p != nullptr) 
        {
            rnd[p] = fp;
            p = p->next;
            if (p == nullptr) fp->next = nullptr;
            else 
            {
                Node* next = new Node(p->val);
                fp->next = next;
            }
            fp = fp->next;
        }

        p = head;
        fp = fakeHead;
        while (p != nullptr) 
        {
            fp->random = rnd[p->random];
            p = p->next;
            fp = fp->next;
        }

        return fakeHead;
    }
};