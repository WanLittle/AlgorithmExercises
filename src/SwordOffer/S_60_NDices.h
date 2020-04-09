#pragma once
#include "../BASE.h"

/*
把n个骰子扔在地上，所有骰子朝上一面的点数之和为s。输入n，打印出s的所有可能的值出现的概率。

你需要用一个浮点数数组返回答案，其中第 i 个元素代表这 n 个骰子所能掷出的点数集合中第 i 小的那个的概率。
*/
class S_60_NDices : public BASE {
public:
	virtual void main()
	{
	}
    vector<double> twoSum(int n) 
    {
        // dp[i][j] 表示掷i次和为s，出现的次数
        vector< vector<int> > dp(12, vector<int>(67, 0)); // 空间可以优化
        for (int i = 1; i <= 6; ++i) 
        {
            dp[1][i] = 1;
        }
        for (int i = 2; i <= n; ++i)
        {
            for (int j = i; j <= 6 * i; ++j)
            {
                for (int k = 1; k <= 6; ++k)
                {                                                                                                         
                    if (j - k <= 0) break;
                    dp[i][j] += dp[i - 1][j - k];
                }
            }
        }
        int all = pow(6, n);
        vector<double> ans(5 * n + 1);
        for (int i = n, k = 0; i <= 6 * n; ++i) 
        {
            ans[k++]  = dp[n][i] * 1.0 / all;
        }
        return ans;
    }
};