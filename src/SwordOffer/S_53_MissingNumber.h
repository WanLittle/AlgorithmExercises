#pragma once
#include "../BASE.h"

// 一个长度为n-1的递增排序数组中的所有数字都是唯一的，并且每个数字都在范围0～n-1之内。
// 在范围0～n-1内的n个数字中有且只有一个数字不在该数组中，请找出这个数字。
class S_53_MissingNumber : public BASE 
{
public:
    virtual void main()
    {
        vector<int> nums = { 0,1,2,3,4,5,6,7,9 };
        cout << missingNumber(nums) << endl;
        // {0}-会输出1
    }
    int missingNumber(vector<int>& nums)
    {
        int low = 0;
        int high = nums.size() - 1;
        while (low <= high)
        {
            int mid = (low + high) * 0.5f;
            if (nums[mid] == mid)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return low;
    }
};