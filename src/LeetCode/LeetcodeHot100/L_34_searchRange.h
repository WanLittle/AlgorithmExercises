#pragma once
#include "../../BASE.h"


class L_34_searchRange : public BASE {
public:
	virtual void main()
	{
		vector<int> nums = { 5, 7, 7, 8, 8, 10 };
		searchRange(nums, 8);
	}
	int bs(vector<int>& nums, int target, bool search_left)
	{
		int l = 0, r = nums.size() - 1;
		int result = 0;
		while (l < r)
		{
			int mid = (l + r) / 2;
			int curr = nums[mid];
			if (search_left)
			{
				if (curr >= target)
				{
					r = mid - 1;
					result = mid;
				}
				else
				{
					l = mid + 1;
				}
			}
			else
			{
				if (curr > target)
				{
					r = mid - 1;
				}
				else
				{
					l = mid + 1;
					result = mid;
				}
			}	
		}
		return result;
	}
	vector<int> searchRange(vector<int>& nums, int target) 
	{
		if (nums.empty()) return { -1, -1 };
		int left = bs(nums, target, true);
		int right = bs(nums, target, false);
		if (nums[left] == target)
			return { left, right };
		return { -1, -1 };
	}
};