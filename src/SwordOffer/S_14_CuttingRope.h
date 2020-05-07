#pragma once
#include "../BASE.h"

/*
给你一根长度为 n 的绳子，请把绳子剪成整数长度的 m 段（m、n都是整数，n>1并且m>1），
每段绳子的长度记为 k[0],k[1]...k[m] 。请问 k[0]*k[1]*...*k[m] 可能的最大乘积是多少？
例如，当绳子的长度是8时，我们把它剪成长度分别为2、3、3的三段，此时得到的最大乘积是18。
*/
class S_14_CuttingRope : public BASE {
public:
	virtual void main()
	{
	}
    int cuttingRope(int n) 
    {
        vector<int> dp(n + 1, 0);
        dp[1] = 1;
        for (int n_p = 2; n_p <= n; ++n_p) 
        {
            for (int i = 1; i <= n_p - 1; ++i) 
            {
                dp[n_p] = max(dp[n_p], i * max(n_p - i, dp[n_p - i]));
            }
        }
        return dp[n];
    }
};