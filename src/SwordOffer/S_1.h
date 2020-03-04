#pragma once
#include "../BASE.h"

class S_1 : public BASE {
public:
	virtual void main()
	{
        cout << cutRope(8) << endl;
	}
    /*
    题目描述
    给你一根长度为n的绳子，请把绳子剪成整数长的m段（m、n都是整数，n>1并且m>1），
    每段绳子的长度记为k[0],k[1],...,k[m]。请问k[0]xk[1]x...xk[m]可能的最大乘积是多少？
    例如，当绳子的长度是8时，我们把它剪成长度分别为2、3、3的三段，此时得到的最大乘积是18。
    */
    int cutRope(int number) 
    {
        vector<int> f(number + 1);
        if (number == 1) //因为一定要剪
            return 1;
        else if (number == 2)
            return 1;
        else if (number == 3)
            return 2;
        else
        {
            f[1] = 1;
            for (int i = 1; i <= number; i++)
            {
                f[i] = i;
                for (int j = 1; j < i; j++)
                {
                    f[i] = std::max(f[i], f[i - j] * f[j]);
                }
            }
            return f[number];
        }
    }
};