#pragma once
#include "../BASE.h"

class S_29_SpiralOrder : public BASE {
public:
	virtual void main()
	{
	}
    vector<int> spiralOrder(vector<vector<int>>& matrix) 
    {
        if (!matrix.size()) return {};
        if (!matrix[0].size()) return matrix[0];

        // 遍历方向:→、↓、←、↑
        vector<int> di = { 0,1,0,-1 };
        vector<int> dj = { 1,0,-1,0 };

        vector<int> Res;
        int row = matrix.size(), col = matrix[0].size();
        int num = row * col;
        int x = 0, y = 0;   //待访问元素坐标
        vector<vector<int>> flag(row, vector<int>(col, 1)); //是否访问过该数组
        int k = 0;  //遍历方向        
        while (Res.size() < num) 
        {
            if (0 <= x && x < row && 0 <= y && y < col && flag[x][y]) 
            {
                Res.push_back(matrix[x][y]);
                flag[x][y] = 0;
            }
            else
            {   //越界或者遇到碰到已访问节点则回溯一个值，然后换个方向继续走
                x -= di[k]; y -= dj[k];
                k = (++k) % 4;
            }
            x += di[k]; y += dj[k];
        }
        return Res;
    };
};