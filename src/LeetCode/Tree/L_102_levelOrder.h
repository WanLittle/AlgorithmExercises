#pragma once
#include "../../BASE.h"


class L_102_levelOrder : public BASE {
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        vector<vector<int>> res;
        if (root != nullptr)
            q.push(root);
        while (!q.empty())
        {
            int currlevelsize = q.size();
            res.push_back(vector<int>());
            for (int i = 0; i < currlevelsize; ++i)
            {
                TreeNode* node = q.front(); q.pop();
                res.back().push_back(node->val);
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
        }
        return res;
    }
};