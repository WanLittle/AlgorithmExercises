#pragma once
#include "../BASE.h"

class S_31 : public BASE {
public:
	virtual void main()
	{
        vector<int> numbers = { 1, -2, 3, 10, -4, 7, 2, -5};
        FindGreatestSumOfSubArray(numbers);
	}

    // 动态规划
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

    //// 分析规律
    //int FindGreatestSumOfSubArray(vector<int> array) {
    //    int max = INT_MIN;
    //    int count = 0;
    //    for (int number : array)
    //    {
    //        count += number;
    //        if (count > max)
    //            max = count;
    //        if (count < 0)
    //            count = 0;
    //    }
    //    return max;
    //}

};