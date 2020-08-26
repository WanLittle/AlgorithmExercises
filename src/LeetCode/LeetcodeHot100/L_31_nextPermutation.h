#pragma once
#include "../../BASE.h"


class L_31_nextPermutation : public BASE {
public:
	virtual void main()
	{
	}
    void nextPermutation(vector<int>& nums) {
        int length = nums.size();
        for (int i = length - 1; i >= 1; --i) {
            if (nums[i] > nums[i - 1]) {
                for (int m = length - 1; m >= 1; --m) {
                    if (nums[m] > nums[i - 1])
                    {
                        swap(nums[m], nums[i - 1]);
                        reverse(nums.begin() + i, nums.end());
                        return;
                    }
                }
            }
        }
        for (int i = 0; i < length / 2; ++i) {
            swap(nums[i], nums[length - i - 1]);
        }
    }
};