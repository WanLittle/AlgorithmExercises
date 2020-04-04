#pragma once
#include "../BASE.h"

// ͳ��һ�����������������г��ֵĴ���
class S_53_CountNumberInOrder : public BASE {
public:
	virtual void main()
	{
        vector<int> nums = { 5,7,7,8,8,10 };
        cout << search(nums, 8) << endl;
	}
    int search(vector<int>& nums, int target) {
        return upper_bound(nums.begin(), nums.end(), target) - lower_bound(nums.begin(), nums.end(), target);
    }
};