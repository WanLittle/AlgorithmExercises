#pragma once
#include "../BASE.h"

/*
一个整型数组 nums 里除两个数字之外，其他数字都出现了两次。
请写程序找出这两个只出现一次的数字。要求时间复杂度是O(n)，空间复杂度是O(1)。
*/
class S_56_FindNumsAppearOnce : public BASE {
public:
	virtual void main()
	{
	}
	void FindNumsAppearOnce(vector<int> data, int* num1, int *num2) 
	{
		auto length = data.size();
		if (length < 2) return;
		int resultOR = 0;
		for (int i = 0; i < length; i++)
			resultOR ^= data[i];
		int indexOfFirst1 = FindFirstBitIs1(resultOR);
		for (int i = 0; i < length; i++)
		{
			if (IsBit1(data[i], indexOfFirst1))
				*num1 ^= data[i];
			else
				*num2 ^= data[i];
		}
	}
	int FindFirstBitIs1(int num)
	{
		int index = 0;
		while ((num & 1) == 0)
		{
			num = num >> 1;
			index++;
		}
		return index;
	}
	bool IsBit1(int num, int indexBit)
	{
		num = num >> indexBit;
		return (num & 1);
	}
};