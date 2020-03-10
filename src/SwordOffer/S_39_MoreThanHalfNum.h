#pragma once
#include "../BASE.h"

// 数组中出现次数超过一半的数字
class S_39_MoreThanHalfNum : public BASE {
public:
	virtual void main()
	{
	}
    int MoreThanHalfNum_Solution(vector<int> numbers)
    {
        int times = 0;
        int number;
        for (auto n : numbers)
        {
            if (times == 0)
            {
                number = n;
                times = 1;
            }
            else
            {
                if (n == number)
                    times++;
                else
                {
                    times--;
                }
            }
        }
        int sum = 0;
        for (auto n : numbers)
        {
            if (n == number)
                sum++;
        }
        if (sum > numbers.size() / 2)
            return number;
        return 0;
    }
};