#pragma once
#include "../BASE.h"

class S_32_LevelOrder1 : public BASE 
{
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
    vector<int> levelOrder(TreeNode* root) 
    {
        vector<int>ret;
        queue<TreeNode*> que;
        que.push(root);
        if (!root)
            return ret;
        TreeNode* temp;
        while (!que.empty()) 
        {
            temp = que.front();
            que.pop();
            ret.push_back(temp->val);
            if (temp->left)
                que.push(temp->left);
            if (temp->right)
                que.push(temp->right);
        }
        return ret;
    }
};