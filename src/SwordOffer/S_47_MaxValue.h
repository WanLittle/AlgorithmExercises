#pragma once
#include "../BASE.h"

/*
在一个 m*n 的棋盘的每一格都放有一个礼物，每个礼物都有一定的价值（价值大于 0）。
你可以从棋盘的左上角开始拿格子里的礼物，并每次向右或者向下移动一格、直到到达棋盘的右下角。
给定一个棋盘及其上面的礼物的价值，请计算你最多能拿到多少价值的礼物？
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

