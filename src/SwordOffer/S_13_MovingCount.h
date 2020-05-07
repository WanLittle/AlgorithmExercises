#pragma once
#include "../BASE.h"

/*
������һ��m��n�еķ��񣬴����� [0,0] ������ [m-1,n-1] ��
һ�������˴����� [0, 0] �ĸ��ӿ�ʼ�ƶ�����ÿ�ο��������ҡ��ϡ����ƶ�һ�񣨲����ƶ��������⣩��
Ҳ���ܽ�������������������λ֮�ʹ���k�ĸ��ӡ�
���磬��kΪ18ʱ���������ܹ����뷽�� [35, 37] ����Ϊ3+5+3+7=18��
�������ܽ��뷽�� [35, 38]����Ϊ3+5+3+8=19��
���ʸû������ܹ�������ٸ����ӣ�
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