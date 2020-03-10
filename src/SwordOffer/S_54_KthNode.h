#pragma once
#include "../BASE.h"

// 二叉搜索树的第k大节点
class S_54_KthNode : public BASE {
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
	TreeNode* KthNode(TreeNode* pRoot, int k)
	{
		return KthNodeCore(pRoot, k);
	}
	TreeNode* KthNodeCore(TreeNode* pRoot, int &k)
	{
		TreeNode* target = nullptr;
		if (pRoot)
		{
			target = KthNodeCore(pRoot->left, k);

			if (target == nullptr)
			{
				if (k == 1)
					return pRoot;
				k--;
			}

			if(target == nullptr)
				target = KthNodeCore(pRoot->right, k);
		}
		return target;
	}
};