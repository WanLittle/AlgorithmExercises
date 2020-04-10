#pragma once
#include "../BASE.h"

/*
��һ������Ϊ n ������ nums ����������ֶ��� 0��n-1 �ķ�Χ�ڡ�
������ĳЩ�������ظ��ģ�����֪���м��������ظ��ˣ�Ҳ��֪��ÿ�������ظ��˼��Ρ�
���ҳ�����������һ���ظ������֡�
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