#pragma once
#include "../BASE.h"

class S_4_FindNumberIn2DArray : public BASE {
public:
	virtual void main()
	{
	}
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) 
    {
        if (matrix.size() == 0) 
        {
            return false;
        }
        int m = matrix.size();
        int n = matrix[0].size();
        int row = m - 1;
        int col = 0;
        while (row >= 0 && col < n) 
        {
            if (matrix[row][col] < target) 
            {
               ++col;
            }
            else if (matrix[row][col] > target) 
            {
                --row;
            }
            else 
            {
                return true;
            }
        }
        return false;
    }
};