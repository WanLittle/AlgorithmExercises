#pragma once
#include "../BASE.h"

class S_32 : public BASE {
public:
	virtual void main()
	{
        cout << NumberOf1Between1AndN_Solution(12) << endl;
	}
    int NumberOf1Between1AndN_Solution(int n)
    {
        int sum = 0;
        for (int i = 0; i <= n; i++)
        {
            sum += numberOf1(i);
        }
        return sum;
    }
    int numberOf1(int sum)
    {
        int result = 0;
        while (sum)
        {
            if(sum % 10 == 1)
                ++result;
            sum = sum / 10;
        }
        return result;
    }
};