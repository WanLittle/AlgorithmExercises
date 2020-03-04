#pragma once
#include "../BASE.h"
#include "TreeNode.h"

class S_39 : public BASE {
public:
	virtual void main()
	{
	}
    int TreeDepth(TreeNode* pRoot)
    {
        if (pRoot == nullptr)
            return 0;
        int nLeft = TreeDepth(pRoot->left);
        int nRight = TreeDepth(pRoot->right);
        return (nLeft > nRight) ? (nLeft + 1) : (nRight + 1);
    }
};