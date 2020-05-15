#pragma once
#include "../BASE.h"

/*
输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历结果。
如果是则返回 true，否则返回 false。假设输入的数组的任意两个数字都互不相同。
*/
class S_33_VerifyPostorder : public BASE {
public:
	virtual void main()
	{
	}
    bool verifyPostorder(vector<int>& postorder) 
    {
        bool res = true;
        if (postorder.empty())
            return res;
        res = helper(postorder, 0, postorder.size() - 1);
        return res;
    }
    bool helper(vector<int>& postorder, int start, int end)
    {
        if (postorder.empty() || start > end)
            return true;
        int root = postorder[end];

        int i = start;
        for (; i < end; ++i)
        {
            if (postorder[i] > root)
                break;
        }

        for (int j = i; j < end; ++j)
        {
            if (postorder[j] < root)
                return false;
        }

        bool left = true;
        if (i > start)
        {
            left = helper(postorder, start, i - 1);
        }
        bool right = true;
        if (i < end - 1)
        {
            right = helper(postorder, i, end - 1);
        }
        return left && right;
    }
};