#pragma once
#include "../BASE.h"

/*
������0123456789101112131415���ĸ�ʽ���л���һ���ַ������С���
��������У���5λ�����±�0��ʼ��������5����13λ��1����19λ��4���ȵȡ�
��дһ���������������nλ��Ӧ�����֡�
*/
class S_44_FindNthDigit : public BASE {
public:
	virtual void main()
	{
        vector<int> numbers = { 0,3,1,6,4};
	}
    int findNthDigit(int n) 
    {
        if (n < 10) 
            return n;
        int base = 1;
        while (n > 9 * pow(10, base - 1) * base)
        {
            n -= 9 * pow(10, base - 1) * base;
            ++base;
        }
        int res = pow(10, base - 1) + n / base;
        int mod = n % base;
        if (mod == 0) 
            return (res - 1) % 10;
        else 
            return res / (int)pow(10, base - mod) % 10;
    }
};