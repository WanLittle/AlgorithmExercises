#pragma once
#include "../BASE.h"

/*
请设计一个函数，用来判断在一个矩阵中是否存在一条包含某字符串所有字符的路径。
路径可以从矩阵中的任意一格开始，每一步可以在矩阵中向左、右、上、下移动一格。
如果一条路径经过了矩阵的某一格，那么该路径不能再次进入该格子。

例如，在下面的3×4的矩阵中包含一条字符串“bfce”的路径（路径中的字母用加粗标出）。

[["a","b","c","e"],
["s","f","c","s"],
["a","d","e","e"]]

但矩阵中不包含字符串“abfb”的路径，
因为字符串的第一个字符b占据了矩阵中的第一行第二个格子之后，路径不能再次进入这个格子。
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