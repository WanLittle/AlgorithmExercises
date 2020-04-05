#pragma once
#include "../BASE.h"

/*
����һ����������������һ������s���������в�����������
ʹ�����ǵĺ�������s������ж�����ֵĺ͵���s�����������һ�Լ��ɡ�
*/
class S_57_TwoSumEqualS : public BASE {
public:
	virtual void main()
	{
	}
	vector<int> twoSum(vector<int> nums, int target)
	{
		vector<int> result;
		int length = nums.size();
		int start = 0, end = length - 1;
		while (start < end)
		{
			if (nums[start] + nums[end] < target)
			{
				start++;
			}
			else if (nums[start] + nums[end] == target)
			{
                result.push_back(nums[start]);
                result.push_back(nums[end]);
                return result;
			}
			else
			{
				end--;
			}
		}
		return result;
	}
};