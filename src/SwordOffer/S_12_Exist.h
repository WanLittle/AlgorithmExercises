#pragma once
#include "../BASE.h"

/*
�����һ�������������ж���һ���������Ƿ����һ������ĳ�ַ��������ַ���·����
·�����ԴӾ����е�����һ��ʼ��ÿһ�������ھ����������ҡ��ϡ����ƶ�һ��
���һ��·�������˾����ĳһ����ô��·�������ٴν���ø��ӡ�

���磬�������3��4�ľ����а���һ���ַ�����bfce����·����·���е���ĸ�üӴֱ������

[["a","b","c","e"],
["s","f","c","s"],
["a","d","e","e"]]

�������в������ַ�����abfb����·����
��Ϊ�ַ����ĵ�һ���ַ�bռ���˾����еĵ�һ�еڶ�������֮��·�������ٴν���������ӡ�
*/
class S_12_Exist : public BASE {
public:
	virtual void main()
	{
	}
    vector<vector<int>> dxy = { {-1, 0}, {1, 0}, {0, 1}, {0, -1} };
    int rows, cols;
    bool dfs(vector<vector<char>>& board, vector<bool>& visit, int i, int j, string& word, int idx) 
    {
        if (board[i][j] != word[idx]) 
            return false;
        visit[i * cols + j] = true;
        ++idx;
        for (auto xy : dxy) 
        {
            int x = xy[0] + i;
            int y = xy[1] + j;
            if (x < 0 || x >= rows || y < 0 || y >= cols || visit[x*cols + y]) 
                continue;
            else 
            {
                if (dfs(board, visit, x, y, word, idx))
                    return true;
            }
        }
        visit[i * cols + j] = false;
        if (idx == word.size()) 
            return  true;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) 
    {
        if (word.empty())  return false;
        rows = board.size();
        cols = board[0].size();
        vector<bool> visit(rows * cols, false);
        for (int i = 0; i < rows; ++i) 
        {
            for (int j = 0; j < cols; ++j) 
            {
                if (board[i][j] == word[0]) 
                {
                    if (dfs(board, visit, i, j, word, 0)) 
                        return true;
                }
            }
        }
        return false;
    }
};