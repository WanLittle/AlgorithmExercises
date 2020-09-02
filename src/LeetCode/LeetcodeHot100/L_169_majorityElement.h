#pragma once
#include "../../BASE.h"


class L_169_majorityElement : public BASE {
public:
	virtual void main()
	{
	}
    int majorityElement(vector<int>& nums) {
        int candidate = -1;
        int count = 0;
        for (int num : nums) {
            if (num == candidate)
                ++count;
            else if (--count < 0) {
                candidate = num;
                count = 1;
            }
        }
        return candidate;
    }
};