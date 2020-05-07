#pragma once
#include "../BASE.h"

/*
����һ������Ϊ n �����ӣ�������Ӽ����������ȵ� m �Σ�m��n����������n>1����m>1����
ÿ�����ӵĳ��ȼ�Ϊ k[0],k[1]...k[m] ������ k[0]*k[1]*...*k[m] ���ܵ����˻��Ƕ��٣�
���磬�����ӵĳ�����8ʱ�����ǰ������ɳ��ȷֱ�Ϊ2��3��3�����Σ���ʱ�õ������˻���18��
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