#pragma once
#include "../BASE.h"

// ������1���ֵĴ���
class S_43_NumberOf1Between1AndN : public BASE {
public:
	virtual void main()
	{
	}
    // ������
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