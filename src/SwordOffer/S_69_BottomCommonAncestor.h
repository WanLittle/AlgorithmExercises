#pragma once
#include "../BASE.h"

/*
二叉树最近公共祖先
*/
class S_69_BottomCommonAncestor : public BASE
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
        if (root == nullptr || p == nullptr || q == nullptr)
            return nullptr;
        list<TreeNode*> path1, path2;
        GetNodePath(root, p, path1);
        GetNodePath(root, q, path2);
        return GetLastCommonNode(path1, path2);
    }
    //获取从根节点到目标节点的路径
    bool GetNodePath(TreeNode* root, TreeNode* node, list<TreeNode*>& path)
    {
        path.push_back(root);
        if (root == node)  
            return true;
        bool found = false;
        if (!found && root->left != NULL)
            found = GetNodePath(root->left, node, path);
        if (!found && root->right != NULL)
            found = GetNodePath(root->right, node, path);
        if (!found)
        {
            path.pop_back();
        }
        return found;
    }
    //获取共同节点
    TreeNode* GetLastCommonNode(list<TreeNode*> path1, list<TreeNode*> path2)
    {
        TreeNode* pLastCommon = nullptr;
        auto it1 = path1.begin();
        auto it2 = path2.begin();
        while (it1 != path1.end() && it2 != path2.end())
        {
            if (*it1 == *it2) 
                pLastCommon = *it1;
            it1++;
            it2++;
        }
        return pLastCommon;
    }
};