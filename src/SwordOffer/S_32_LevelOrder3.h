#pragma once
#include "../BASE.h"
class S_32_LevelOrder3 : public BASE
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
    vector<vector<int>> levelOrder(TreeNode* root)
    {
        vector<vector<int>> res;
        vector<int> cur;
        queue<TreeNode*> que;
        que.push(root);
        if (!root)
            return res;
        TreeNode* temp;
        int current = 1;
        int next = 0;
        bool even = false; // Å¼ÊýÐÐ
        while (!que.empty())
        {
            temp = que.front();
            que.pop();
            --current;
            cur.push_back(temp->val);
            if (temp->left)
            {
                ++next;
                que.push(temp->left);
            }
            if (temp->right)
            {
                ++next;
                que.push(temp->right);
            }
            if (0 == current)
            {
                if(even)
                    reverse(cur.begin(), cur.end());
                even = !even;
                res.push_back(cur);
                cur.clear();
                current = next;
                next = 0;
            }
        }
        return res;
    }
};