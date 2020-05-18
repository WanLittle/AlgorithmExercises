#pragma once
#include "../BASE.h"

/*
输入一棵二叉树和一个整数，打印出二叉树中节点值的和为输入整数的所有路径。

从树的根节点开始往下一直到叶节点所经过的节点形成一条路径。
*/
class S_34_PathSum : public BASE {
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
    vector<vector<int>> pathSum(TreeNode* root, int sum) 
    {
        vector<vector<int>> res;
        if (root == nullptr) return res;
        vector<int> path;
        FindPath(root, res, path, sum, 0);
        return res;
    }
    void FindPath(TreeNode* root, vector<vector<int>>& res, vector<int>& path, int expectedSum, int currentSum)
    {

        currentSum += root->val;
        path.push_back(root->val);
        bool isLeaf = (root->left == nullptr && root->right == nullptr);
        if (currentSum == expectedSum && isLeaf)
        {
            res.push_back(path);
        }
        if (root->left != nullptr) 
            FindPath(root->left, res, path, expectedSum, currentSum);
        if (root->right != nullptr) 
            FindPath(root->right, res, path, expectedSum, currentSum);
        path.pop_back();
    }
};