#pragma once
#include "../BASE.h"

// ����һ��double���͵ĸ�����base��int���͵�����exponent����base��exponent�η���
// ��֤base��exponent��ͬʱΪ0
class S_16_MyPow : public BASE {
public:
	virtual void main()
	{
        cout << Power(2.0, -2) << endl;
	}
    double Power(double base, int exponent)
    {
        long long unsigned_exp = exponent;
        if (unsigned_exp < 0) unsigned_exp = -unsigned_exp;
        return exponent > 0 ? powWithUnsignExp(base, unsigned_exp) : 1.0 / powWithUnsignExp(base, unsigned_exp);
    }

    double powWithUnsignExp(double base, int exp) //a^n = a ^ (n/2) * a ^ (n/2)
    {
        if (exp == 0)
            return 1;
        if (exp == 1)
            return base;
        double result = powWithUnsignExp(base, exp >> 1);
        result = result * result;
        if (exp & 0x1 == 1) result = result * base;
        return result;
    }
    /*
    double powWithUnsignExp(double base, unsigned int exp) //����
    {
        double result = 1.0;
        for (unsigned int i = 0; i < exp; ++i)
        {
            result = result * base;
        }
        return result;
    }
    */

};