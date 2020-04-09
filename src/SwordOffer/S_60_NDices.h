#pragma once
#include "../BASE.h"

/*
��n���������ڵ��ϣ��������ӳ���һ��ĵ���֮��Ϊs������n����ӡ��s�����п��ܵ�ֵ���ֵĸ��ʡ�

����Ҫ��һ�����������鷵�ش𰸣����е� i ��Ԫ�ش����� n ���������������ĵ��������е� i С���Ǹ��ĸ��ʡ�
*/
class S_60_NDices : public BASE {
public:
	virtual void main()
	{
	}
    vector<double> twoSum(int n) 
    {
        // dp[i][j] ��ʾ��i�κ�Ϊs�����ֵĴ���
        vector< vector<int> > dp(12, vector<int>(67, 0)); // �ռ�����Ż�
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