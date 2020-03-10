#pragma once
#include "../BASE.h"

// 输入n个整数，找出其中最小的K个数。例如输入4,5,1,6,2,7,3,8这8个数字，则最小的4个数字是1,2,3,4,。
class S_40_GetKLeastNumbers : public BASE {
public:
	virtual void main()
	{
	}

    // 用大顶堆实现最佳。但是略复杂，所以使用 STL 里的 multiset 底层是红黑树
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k)
    {
        std::multiset<int, greater<int>> leastNumber;
        vector<int> result;
        if (input.size() < k)
            return result;
        result.reserve(k);
        for (int number : input)
        {
            if (leastNumber.size() < k)
            {
                leastNumber.insert(number);
            }
            else
            {
                auto biggestIter = leastNumber.begin();
                if (*biggestIter > number)
                {
                    leastNumber.erase(biggestIter);
                    leastNumber.insert(number);
                }
            }
        }
        for (auto number : leastNumber)
        {
            result.push_back(number);
        }
        return result;
    }

    // 排序
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k)
    {
        vector<int> result;
        if (input.size() < k)
            return result;
        sort(input.begin(), input.end(), [](int a, int b) {return a < b;});
        result.reserve(k);
        for (size_t i = 0; i < k; i++)
        {
            result.push_back(input[i]);
        }
        return result;
    }

};