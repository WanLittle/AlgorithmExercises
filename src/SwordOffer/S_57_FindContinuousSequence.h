#pragma once
#include "../BASE.h"

/*
输入一个正整数 target ，输出所有和为 target 的连续正整数序列（至少含有两个数）。

序列内的数字由小到大排列，不同序列按照首个数字从小到大排列。
*/
class S_57_FindContinuousSequence : public BASE {
public:
	virtual void main()
	{
	}
    vector<vector<int>> findContinuousSequence(int target) 
    {
        int left = 1; // 滑动窗口的左边界
        int right = 1; // 滑动窗口的右边界
        int sum = 0; // 滑动窗口中数字的和
        vector<vector<int>> res;
        while (left <= target / 2) 
        {
            if (sum < target) // 右边界右移
            {
                sum += right;
                right++;
            }
            else if (sum > target) // 左边界右移
            {
                sum -= left;
                left++;
            }
            else // 记录结果
            {
                vector<int> arr;
                for (int k = left; k < right; k++) 
                {
                    arr.push_back(k);
                }
                res.push_back(arr);
                // 左边界向右移动
                sum -= left;
                left++;
            }
        }
        return res;
    }
};