#pragma once
#include "../BASE.h"

/*
��ʵ��һ�������������ж�һ�ö������ǲ��ǶԳƵġ�
���һ�ö����������ľ���һ������ô���ǶԳƵġ�
*/
class S_28_SymmetricBinTree : public BASE {
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
    bool isSymmetric(TreeNode* root) 
    {
        return isSymmetric(root, root);
    }
    bool isSymmetric(TreeNode* root1, TreeNode* root2)
    {
        if (root1 == nullptr && root2 == nullptr)
            return true;
        if (root1 == nullptr || root2 == nullptr)
            return false;
        if (root1->val != root2->val)
            return false;
        return isSymmetric(root1->left, root2->right)
            && isSymmetric(root1->right, root2->left);
    }
};