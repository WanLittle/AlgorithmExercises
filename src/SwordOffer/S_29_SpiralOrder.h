#pragma once
#include "../BASE.h"

class S_29_SpiralOrder : public BASE {
public:
	virtual void main()
	{
	}
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) 
    {
        if (!matrix.size()) return {};
        if (!matrix[0].size()) return matrix[0];

        // ��ʾ����:��������������
        vector<int> di = { 0,1,0,-1 };
        vector<int> dj = { 1,0,-1,0 };

        vector<int> Res;
        int row = matrix.size(), col = matrix[0].size();
        int num = row * col;    //����Ԫ�ظ���
        int x = 0, y = 0;   //������Ԫ������
        vector<vector<int>> flag(row, vector<int>(col, 1)); //�Ƿ���ʹ�������
        int k = 0;  //��������        
        while (Res.size() < num) 
        {
            if (0 <= x && x < row && 0 <= y && y < col && flag[x][y]) 
            {
                Res.push_back(matrix[x][y]);
                flag[x][y] = 0;
            }
            else
            {   //Խ��������������ѷ��ʽڵ������һ��ֵ��Ȼ�󻻸����������
                x -= di[k]; y -= dj[k];
                k = (++k) % 4;
            }
            x += di[k]; y += dj[k];
        }
        return Res;
    };
};