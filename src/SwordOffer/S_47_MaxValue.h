#pragma once
#include "../BASE.h"

/*
��һ�� m*n �����̵�ÿһ�񶼷���һ�����ÿ�����ﶼ��һ���ļ�ֵ����ֵ���� 0����
����Դ����̵����Ͻǿ�ʼ�ø�����������ÿ�����һ��������ƶ�һ��ֱ���������̵����½ǡ�
����һ�����̼������������ļ�ֵ���������������õ����ټ�ֵ�����
*/
class S_47_MaxValue : public BASE {
public:
    
	virtual void main()
	{
	}
    int maxValue(vector<vector<int>>& grid)
    {
        int rows = grid.size(),
            cols = grid[0].size();
        vector<int> dp(cols, 0);
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                int left = 0;
                int up = 0;
                if (i > 0)
                    up = dp[j];
                if (j > 0)
                    left = dp[j - 1];
                dp[j] = max(left, up) + grid[i][j];
            }
        }
        return dp[cols - 1];
    }
};

