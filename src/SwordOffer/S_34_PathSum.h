#pragma once
#include "../BASE.h"

/*
����һ�ö�������һ����������ӡ���������нڵ�ֵ�ĺ�Ϊ��������������·����

�����ĸ��ڵ㿪ʼ����һֱ��Ҷ�ڵ��������Ľڵ��γ�һ��·����
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