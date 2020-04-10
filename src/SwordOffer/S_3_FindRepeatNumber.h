#pragma once
#include "../BASE.h"

/*
在一个长度为 n 的数组 nums 里的所有数字都在 0～n-1 的范围内。
数组中某些数字是重复的，但不知道有几个数字重复了，也不知道每个数字重复了几次。
请找出数组中任意一个重复的数字。
*/
class S_3_FindRepeatNumber : public BASE {
public:
	virtual void main()
	{
        vector<int> nums = { 0, 1, 2, 0, 4, 5, 6, 7, 8, 9 };
        cout << findRepeatNumber(nums) << endl;
	}
    int findRepeatNumber(vector<int>& nums) 
    {
        for (int i = 0; i < nums.size(); i++) 
        {
            while (nums[i] != i) 
            {
                if (nums[i] == nums[nums[i]]) 
                {
                    return nums[i];
                }
                else 
                {
                    swap(nums[i], nums[nums[i]]);
                }
            }
        }
        return -1;
    }
};