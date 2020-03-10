#pragma once
#include "../BASE.h"

class S_15_CountBitOne : public BASE {
public:
	virtual void main()
	{
	}
    int  NumberOf1(int n)
    {
        int count = 0;
        while (n)
        {
            count++;
            n = (n - 1) & n;
        }
        return count;
    }
    int  NumberOf1_a2(int n)
    {
        int count = 0;
        int flag = 1;
        while (flag)
        {
            if (n & flag)
                count++;
            flag = flag << 1;
        }
        return count;
    }
};