#pragma once
#include "../BASE.h"

/*
数字以0123456789101112131415…的格式序列化到一个字符序列中。在
这个序列中，第5位（从下标0开始计数）是5，第13位是1，第19位是4，等等。
请写一个函数，求任意第n位对应的数字。
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