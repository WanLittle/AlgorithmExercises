#pragma once
#include "../BASE.h"

// 二叉树的深度
class S_55_TreeDepth : public BASE {
public:
	virtual void main()
	{
	}
    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    };
    int TreeDepth(TreeNode* pRoot)
    {
        if (pRoot == nullptr)
            return 0;
        int nLeft = TreeDepth(pRoot->left);
        int nRight = TreeDepth(pRoot->right);
        return (nLeft > nRight) ? (nLeft + 1) : (nRight + 1);
    }
};