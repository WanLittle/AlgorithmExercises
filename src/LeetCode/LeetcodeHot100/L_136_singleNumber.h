#pragma once
#include "../../BASE.h"


class L_136_singleNumber : public BASE {
public:
	virtual void main()
	{
	}
    int singleNumber(vector<int>& nums) {
        int res = nums[0];
        for (int i = 1; i < nums.size(); ++i)
            res ^= nums[i];
        return res;
    }
};