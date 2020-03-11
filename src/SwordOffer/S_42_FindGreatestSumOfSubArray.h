#pragma once
#include "../BASE.h"

class S_42_FindGreatestSumOfSubArray : public BASE {
public:
	virtual void main()
	{
	}
    // ¶¯Ì¬¹æ»®
    int FindGreatestSumOfSubArray(vector<int> array) {
        vector<int> f(array.size());
        for (size_t i = 0; i < array.size(); i++)
        {
            if (i == 0 || f[i - 1] < 0)
                f[i] = array[i];
            else
            {
                f[i] = array[i] + f[i - 1];
            }
        }
        int result = f[0];
        for (auto fi : f)
        {
            result = std::max(result, fi);
        }
        return result;
    }
};