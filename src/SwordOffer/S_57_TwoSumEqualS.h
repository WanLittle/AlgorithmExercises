#pragma once
#include "../BASE.h"

/*
输入一个递增排序的数组和一个数字s，在数组中查找两个数，
使得它们的和正好是s。如果有多对数字的和等于s，则输出任意一对即可。
*/
class S_57_TwoSumEqualS : public BASE {
public:
	virtual void main()
	{
	}
	vector<int> twoSum(vector<int> nums, int target)
	{
		vector<int> result;
		int length = nums.size();
		int start = 0, end = length - 1;
		while (start < end)
		{
			if (nums[start] + nums[end] < target)
			{
				start++;
			}
			else if (nums[start] + nums[end] == target)
			{
                result.push_back(nums[start]);
                result.push_back(nums[end]);
                return result;
			}
			else
			{
				end--;
			}
		}
		return result;
	}
};