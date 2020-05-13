#pragma once
#include "../BASE.h"

class S_8_GetNext : public BASE {
public:
	virtual void main()
	{
	}
    struct TreeLinkNode {
        int val;
        struct TreeLinkNode *left;
        struct TreeLinkNode *right;
        struct TreeLinkNode *next;
        TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {

        }
    };
    TreeLinkNode* GetNext(TreeLinkNode* pNode)
    {
        if (pNode == nullptr)
            return nullptr;
        if (pNode->right != nullptr)
        {
            pNode = pNode->right;
            while (pNode->left != nullptr)
                pNode = pNode->left;
            return pNode;
        }
        else if (pNode->next != nullptr)
        {
            TreeLinkNode *parent = pNode->next;
            while (parent != nullptr && pNode == parent->right)
            {
                pNode = parent;
                parent = pNode->next;
            }
            return parent;
        }
        return nullptr;
    }
};