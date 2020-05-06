#pragma once
#include "../BASE.h"

/*
��һ�������ʼ�����ɸ�Ԫ�ذᵽ�����ĩβ�����ǳ�֮Ϊ�������ת��
����һ����������������һ����ת�������ת�������СԪ�ء�
���磬���� [3,4,5,1,2] Ϊ [1,2,3,4,5] ��һ����ת�����������СֵΪ1��
*/
class S_11_MinArray : public BASE {
public:
	virtual void main()
	{
	}
    int minArray(vector<int>& numbers) 
    {
        if (numbers.empty())
            return 0;
        int n = numbers.size();
        int left = 0;
        int right = n - 1;
        while (left < right)
        {
            int mid = (left + right) / 2;
            if (numbers[mid] > numbers[right])
                left = mid + 1;
            else if (numbers[mid] == numbers[right])
                right--;
            else
                right = mid;
        }
        return numbers[right];
    }
};