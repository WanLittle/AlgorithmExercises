#pragma once
#include "../BASE.h"

// �������ö�����A��B���ж�B�ǲ���A���ӽṹ����ps������Լ��������������һ�������ӽṹ��
class S_26_HasSubtree : public BASE {
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
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
    {
        bool result = false;
        if (pRoot1 != nullptr && pRoot2 != nullptr)
        {
            if (pRoot1->val == pRoot2->val)
                result = doesTree2InTree1(pRoot1, pRoot2);
            if (!result)
                result = HasSubtree(pRoot1->left, pRoot2);
            if (!result)
                result = HasSubtree(pRoot1->right, pRoot2);
        }
        return result;
    }
    bool doesTree2InTree1(TreeNode* pRoot1, TreeNode* pRoot2)
    {
        if (pRoot2 == nullptr)
            return true;
        if (pRoot1 == nullptr)
            return false;
        if (pRoot1->val != pRoot2->val)
            return false;
        return doesTree2InTree1(pRoot1->left, pRoot2->left)
            && doesTree2InTree1(pRoot1->right, pRoot2->right);
    }
};