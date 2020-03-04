#pragma once
#include "../BASE.h"



class S_48 : public BASE {
public:
	virtual void main()
	{
	}
    int Add(int num1, int num2)
    {
        int sum;
        do 
        {
            sum = num1 ^ num2; //异或等同于相加，但是不处理进位
            num2 = (num1 & num2) << 1; //&之后<<，只处理进位
            num1 = sum;
        } while (num2 != 0);
        return num1;
    }
};