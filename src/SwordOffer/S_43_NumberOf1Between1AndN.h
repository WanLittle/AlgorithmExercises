#pragma once
#include "../BASE.h"

// 整数中1出现的次数
class S_43_NumberOf1Between1AndN : public BASE {
public:
	virtual void main()
	{
	}
    // 暴力法
    int NumberOf1Between1AndN_Solution(int n)
    {
        int sum = 0;
        for (int i = 0; i <= n; i++)
        {
            sum += numberOf1(i);
        }
        return sum;
    }
    inline int numberOf1(int sum)
    {
        int result = 0;
        while (sum)
        {
            if (sum % 10 == 1)
                ++result;
            sum = sum / 10;
        }
        return result;
    }
};