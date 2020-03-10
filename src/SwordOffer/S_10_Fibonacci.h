#pragma once
#include "../BASE.h"

// ì³²¨ÄÇÆõÊýÁÐ
class S_10_Fibonacci : public BASE {
public:
	virtual void main()
	{
	}

    int Fibonacci(int n) 
    {
        int f[2] = { 0, 1 };
        if (n < 2)
            return f[n];
        int f_n, f_n1 = f[1], f_n2 = f[0];
        for (int i = 2; i <= n; i++)
        {
            f_n = f_n1 + f_n2;
            f_n2 = f_n1;
            f_n1 = f_n;
        }
        return f_n;
    }

};