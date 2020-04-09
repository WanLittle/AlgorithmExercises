#pragma once
#include "../BASE.h"

/*
���˿����������5���ƣ��ж��ǲ���һ��˳�ӣ�����5�����ǲ��������ġ�
2��10Ϊ���ֱ���AΪ1��JΪ11��QΪ12��KΪ13��
����С��Ϊ 0 �����Կ����������֡�A ������Ϊ 14��
*/
class S_61_IsStraight : public BASE {
public:
	virtual void main()
	{
		
	}
    bool isStraight(vector<int>& nums) 
    {
        sort(nums.begin(), nums.end());
        int zero = 0;
        for (int i = 0; i < 4; ++i) 
        {
            if (nums[i] == 0) 
            {
                ++zero;
                continue;
            }
            if (nums[i] == nums[i + 1]) 
            {
                return false;
            }
            zero -= nums[i + 1] - nums[i] - 1;
        }
        return zero >= 0;
    }
};