#pragma once
#include "../BASE.h"

/*
在一个长度为 n+1 的数组 nums 里的所有数字都在 0～n-1 的范围内。
请找出数组中任意一个重复的数字。
*/
class S_3_FindRepeatNumber2 : public BASE {
public:
    virtual void main()
    {
        vector<int> nums = { 0, 1, 2, 0, 4, 5, 6, 7, 8, 9 };
        cout << findRepeatNumber(nums) << endl;
    }

    int findRepeatNumber(vector<int>& nums)
    {
        if (nums.empty()) return -1;
        int start = 0;
        int end = nums.size() - 1;
        while (start <= end)
        {
            int mid = (start + end) / 2;
            int count = count_if(nums.begin(), nums.end(),
                [mid, start](int num) { return num <= mid && num >= start; });
            if (start == end)
                return start;
            if (count > (mid - start + 1))
                end = mid;
            else
                start = mid + 1;
        }
        return -1;
    }
};