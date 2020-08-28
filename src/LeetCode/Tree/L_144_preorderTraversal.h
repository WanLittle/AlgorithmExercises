#pragma once
#include "../../BASE.h"


class L_144_preorderTraversal : public BASE {
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

    // Õ» + µü´ú
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        vector<int> res;
        if (root != nullptr)
            st.push(root);
        while (!st.empty())
        {
            TreeNode* curr = st.top();
            res.push_back(curr->val);
            st.pop();
            if (curr->right)
                st.push(curr->right);
            if (curr->left)
                st.push(curr->left);
        }
        return res;
    }

    // µÝ¹é
    vector<int> preorderTraversal2(TreeNode* root)
    {
        vector<int> result;
        inorder(result, root);
        return result;
    }
    void inorder(vector<int>& result, TreeNode* root)
    {
        if (root == NULL)
            return;
        result.push_back(root->val);
        if (root->left != NULL)
            inorder(result, root->left);
        if (root->right != NULL)
            inorder(result, root->right);
    }

};