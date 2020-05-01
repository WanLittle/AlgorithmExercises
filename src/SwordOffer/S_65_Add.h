#pragma once
#include "../BASE.h"

/*
不用加减乘除做加法
*/
class S_65_Add : public BASE
{
public:
    virtual void main()
    {

    }
    int add(int a, int b)
    {
        int sum;
        int carry;
        while (b)
        {
            sum = a ^ b;
            carry = (unsigned int)(a & b) << 1;
            a = sum;
            b = carry;
        }
        return a;
    }
};