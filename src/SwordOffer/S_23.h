#pragma once
#include "../BASE.h"
#include "TreeNode.h"

class S_23 : public BASE {
public:
	virtual void main()
	{
	}
    /*
    ��Ŀ����
    �������´�ӡ����������ÿ���ڵ㣬ͬ��ڵ�������Ҵ�ӡ��
    */
    vector<int> PrintFromTopToBottom(TreeNode* root) 
    {
        vector<int> result;
        if (root == nullptr)
            return result;
        queue<TreeNode*> q;
        TreeNode* t;
        q.push(root);
        while (!q.empty())
        {
            t = q.front();
            result.push_back(t->val);
            if (t->left)
                q.push(t->left);
            if (t->right)
                q.push(t->right);
            q.pop();
        }
        return result;
    }
};