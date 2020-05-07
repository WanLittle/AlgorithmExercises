#pragma once
#include "../BASE.h"

/*
地上有一个m行n列的方格，从坐标 [0,0] 到坐标 [m-1,n-1] 。
一个机器人从坐标 [0, 0] 的格子开始移动，它每次可以向左、右、上、下移动一格（不能移动到方格外），
也不能进入行坐标和列坐标的数位之和大于k的格子。
例如，当k为18时，机器人能够进入方格 [35, 37] ，因为3+5+3+7=18。
但它不能进入方格 [35, 38]，因为3+5+3+8=19。
请问该机器人能够到达多少个格子？
*/
class S_13_MovingCount : public BASE {
public:
	virtual void main()
	{
	}
    int getDigitSum(int num) 
    {
        int res = 0;
        while(num) 
        {
            res += num % 10;
            num /= 10;
        }
        return res;
    }
    int movingCount(int m, int n, int k) 
    {
        int res = 1;
        if (!k) return res;
        queue<pair<int, int> > Q;
        int dx[4] = { 0, 1, 0, -1};
        int dy[4] = { 1, 0, -1, 0};
        vector<vector<int> > vis(m, vector<int>(n, 0));
        Q.push(make_pair(0, 0));
        vis[0][0] = 1;
        while (!Q.empty()) 
        {
            auto p = Q.front();
            Q.pop();
            for (int i = 0; i < 4; ++i) 
            {
                int tx = dx[i] + p.first;
                int ty = dy[i] + p.second;
                if (tx < 0 || tx >= m || ty < 0 || ty >= n || vis[tx][ty] || getDigitSum(tx) + getDigitSum(ty) > k) 
                    continue;
                Q.push(make_pair(tx, ty));
                vis[tx][ty] = 1;
                res++;
            }
        }
        return res;
    }
};