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
            sum = num1 ^ num2; //����ͬ����ӣ����ǲ������λ
            num2 = (num1 & num2) << 1; //&֮��<<��ֻ�����λ
            num1 = sum;
        } while (num2 != 0);
        return num1;
    }
};