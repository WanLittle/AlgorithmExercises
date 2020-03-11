#pragma once
#include "../BASE.h"

class S_27_MirrorBinTree : public BASE {
public:
	virtual void main()
	{
	}
    struct TreeNode
    {
        int val;
        struct TreeNode *left;
        struct TreeNode *right;
        TreeNode(int x) : val(x), left(NULL), right(NULL) { }
    };
    void Mirror(TreeNode *pRoot) 
    {
        if (pRoot == nullptr)
            return;
        if (pRoot->left == nullptr && pRoot->right == nullptr)
            return;
        TreeNode *t = pRoot->left;
        pRoot->left = pRoot->right;
        pRoot->right = t;
        Mirror(pRoot->left);
        Mirror(pRoot->right);
    }
};