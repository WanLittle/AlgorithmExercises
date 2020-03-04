#pragma once
#include "../BASE.h"
#include "TreeNode.h"

class S_23 : public BASE {
public:
	virtual void main()
	{
	}
    /*
    题目描述
    从上往下打印出二叉树的每个节点，同层节点从左至右打印。
    */
    vector<int> PrintFromTopToBottom(TreeNode* root) 
    {
        vector<int> result;
        if (root == nullptr)
            return result;
        queue<TreeNode*> q;
        TreeNode* t;
        q.push(root);
        while (!q.empty())
        {
            t = q.front();
            result.push_back(t->val);
            if (t->left)
                q.push(t->left);
            if (t->right)
                q.push(t->right);
            q.pop();
        }
        return result;
    }
};