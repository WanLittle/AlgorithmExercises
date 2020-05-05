#pragma once
#include "../BASE.h"

/*
二叉搜索树最近公共祖先
*/
class S_68_LowestCommonAncestor : public BASE
{
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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
    {
        if (!(root && root && root))
            return nullptr;
        TreeNode* tran = root;
        while (tran != nullptr)
        {
            if (tran->val > p->val && tran->val > q->val)
            {
                tran = tran->left;
            }
            else if (tran->val < p->val && tran->val < q->val)
            {
                tran = tran->right;
            }
            else
                return tran;
        }
        return tran;
    }
};