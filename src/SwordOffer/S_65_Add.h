#pragma once
#include "../BASE.h"

/*
���üӼ��˳����ӷ�
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