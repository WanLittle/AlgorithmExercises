#pragma once
#include "../../BASE.h"


class L_114_flatten : public BASE {
public:
	virtual void main()
	{
	}

    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode() : val(0), left(nullptr), right(nullptr) {}
        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
    };

    void flatten(TreeNode* root) {
        if (root == nullptr) return;
        auto curr = root;
        while (curr) {
            TreeNode* const right = curr->right;
            TreeNode* const left = curr->left;
            if (left == nullptr) {
                curr = curr->right;
            }
            else {
                auto left_rightmost = left;
                while (left_rightmost->right != nullptr) {
                    left_rightmost = left_rightmost->right;
                }
                left_rightmost->right = right;
                curr->left = nullptr;
                curr->right = left;
                curr = curr->right;
            }
        }
    }

};