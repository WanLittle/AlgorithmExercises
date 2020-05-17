#pragma once
#include "../BASE.h"

class S_42_MaxSubArray : public BASE {
public:
    virtual void main()
    {
    }
    int maxSubArray(vector<int>& nums) 
    {
        vector<int> f(nums.size());
        for (size_t i = 0; i < nums.size(); i++)
        {
            if (i == 0 || f[i - 1] < 0)
                f[i] = nums[i];
            else
                f[i] = nums[i] + f[i - 1];
        }
        return *max_element(f.begin(), f.end());
    }
};