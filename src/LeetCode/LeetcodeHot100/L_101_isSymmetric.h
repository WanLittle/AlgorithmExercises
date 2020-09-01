#pragma once
#include "../../BASE.h"


class L_101_isSymmetric : public BASE {
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

    // µü´ú
    bool isSymmetric(TreeNode* root) {
        queue <TreeNode*> q;
        auto u = root, v = root;
        q.push(u); q.push(v);
        while (!q.empty()) {
            u = q.front(); q.pop();
            v = q.front(); q.pop();
            if (!u && !v) continue;
            if ((!u || !v) || (u->val != v->val)) return false;

            q.push(u->left);
            q.push(v->right);

            q.push(u->right);
            q.push(v->left);
        }
        return true;
    }


    // µÝ¹é
    bool isSymmetric2(TreeNode* root) {
        return dfs(root, root);
    }
    bool dfs(TreeNode* p, TreeNode* q)
    {
        if (!p && !q)
            return true;
        if (!p || !q)
            return false;
        return p->val == q->val && dfs(p->left, q->right) && dfs(p->right, q->left);
    }
};