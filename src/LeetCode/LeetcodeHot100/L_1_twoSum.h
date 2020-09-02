#pragma once
#include "../../BASE.h"


class L_1_twoSum : public BASE {
public:
	virtual void main()
	{
	}

    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        unordered_map<int, int> hash;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (hash.count(target - nums[i]) > 0)
            {
                result.push_back(hash[target - nums[i]]);
                result.push_back(i);
                return result;
            }
            hash[nums[i]] = i;
        }
        return result;
    }
};