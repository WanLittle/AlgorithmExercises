#pragma once
#include "../BASE.h"

#include "TreeNode.h"

class S_54 : public BASE {
public:
	virtual void main()
	{

	}
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