#pragma once
#include "../BASE.h"

class S_20 : public BASE {
public:
	virtual void main()
	{
        vector<vector<int> > matrix = 
        {
            {1,2,3},
            //{8,9,4},
            //{7,6,5}
        };
        for (auto f : printMatrix(matrix))
        {
            cout << f << " ";
        }
	}
    vector<int> printMatrix(vector<vector<int> > matrix) 
    {
        vector<int> result;
        if (matrix.empty())
            return result;
        int rows = matrix.size(), columns = matrix[0].size();
        int start = 0;
        while (columns > 2 * start && rows > 2 * start)
        {
            printMatrixCircle(result, matrix, rows, columns, start);
            start++;
        }
        return result;
    }

    void printMatrixCircle(vector<int> &result, vector<vector<int>> &matrix, int rows, int columns, int start)
    {
        int endRow = rows - start - 1, endColumn = columns - start - 1;
        if (start <= endColumn)
        {
            for (int i = start; i <= endColumn; i++)
            {
                result.push_back(matrix[start][i]);
            }
            if (start + 1 <= endRow)
            {
                for (int i = start + 1; i <= endRow; i++)
                {
                    result.push_back(matrix[i][endColumn]);
                }
                if (start <= endColumn - 1)
                {
                    for (int i = endColumn - 1; i >= start; i--)
                    {
                        result.push_back(matrix[endRow][i]);
                    }
                    if (start <= endColumn - 1 && start + 1 <= endRow - 1)
                    {
                        for (int i = endRow - 1; i >= start + 1; i--)
                        {
                            result.push_back(matrix[i][start]);
                        }
                    }
                }
            }
        }
    }


};