#pragma once
#include "../BASE.h"
#include "TreeNode.h"

class S_39_2 : public BASE {
public:
    virtual void main()
    {

    }

    bool IsBalanced_Solution(TreeNode* pRoot) 
    {
        int depth;
        return IsBalanced(pRoot, depth);
    }

    bool IsBalanced(TreeNode* pRoot, int &depth)
    {
        if (pRoot == nullptr)
        {
            depth = 0;
            return true;
        }
        int left, right;
        if (IsBalanced(pRoot->left, left) && IsBalanced(pRoot->right, right))
        {
            int diff = std::abs(left - right);
            if (diff <= 1)
            {
                depth = std::max(left, right) + 1;
                return true;
            }
        }
        return false;
    }

};