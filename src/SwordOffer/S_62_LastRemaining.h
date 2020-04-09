#pragma once
#include "../BASE.h"
/*
0,1,,n-1这n个数字排成一个圆圈，从数字0开始，每次从这个圆圈里删除第m个数字。求出这个圆圈里剩下的最后一个数字。
*/

class S_62_LastRemaining : public BASE
{
public:
    virtual void main()
    {

    }

    int lastRemaining(int n, int m) 
    {
        int last = 0;
        for (int i = 2; i <= n; ++i)
        {
            last = (last + m) % i;
        }
        return last;
    }
};