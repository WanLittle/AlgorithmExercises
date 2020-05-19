#pragma once
#include "../BASE.h"

class S_36_TreeToDoublyList : public BASE {
public:
	virtual void main()
	{
	}
    class Node {
    public:
        int val;
        Node* left;
        Node* right;

        Node() {}

        Node(int _val) {
            val = _val;
            left = NULL;
            right = NULL;
        }

        Node(int _val, Node* _left, Node* _right) {
            val = _val;
            left = _left;
            right = _right;
        }
    };

    Node *pre = nullptr, *head = nullptr;
    Node* treeToDoublyList(Node* root) 
    {
        if (!root) 
            return nullptr;
        helper(root);
        head->left = pre;
        pre->right = head;
        return head;
    }
    void helper(Node* cur) 
    {
        if (!cur)  return;
        helper(cur->left);

        if (pre == nullptr)
        {
            head = cur;
        }
        else
        {
            pre->right = cur;
            cur->left = pre;
        }
        pre = cur;
            
        helper(cur->right);
    }

};