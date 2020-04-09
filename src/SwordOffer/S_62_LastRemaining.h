#pragma once
#include "../BASE.h"
/*
0,1,,n-1��n�������ų�һ��ԲȦ��������0��ʼ��ÿ�δ����ԲȦ��ɾ����m�����֡�������ԲȦ��ʣ�µ����һ�����֡�
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