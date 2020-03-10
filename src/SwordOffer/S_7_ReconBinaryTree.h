#pragma once
#include "../BASE.h"

// 根据前序中序重建二叉树
class S_7_ReconBinaryTree : public BASE {
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
    
    TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> vin) 
    {
        int n = pre.size();
        int m = vin.size();
        if (n != m || n == 0)
            return NULL;
        return construct(pre, vin, 0, n - 1, 0, m - 1);
    }

    TreeNode* construct(vector<int>& pre, vector<int>& vin, int l1, int r1, int l2, int r2)
    {
        TreeNode* root = new TreeNode(pre[l1]);
        if (r1 == l1)
        {
            return root;
        }
        int val = pre[l1];
        int index;
        for (index = l2; index <= r2; index++)
        {
            if (vin[index] == val)
                break;
        }
        int left_tree_len = index - l2;
        int right_tree_len = r2 - index;
        if (left_tree_len > 0)
            root->left = construct(pre, vin, l1 + 1, l1 + left_tree_len, l2, index - 1);
        if (right_tree_len > 0)
            root->right = construct(pre, vin, l1 + 1 + left_tree_len, r1, index + 1, r2);
        return root;
    }
};