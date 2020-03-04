#pragma once
#include "../BASE.h"

class S_29 : public BASE {
public:
	virtual void main()
	{
        vector<int> numbers = { 1, 2, 3, 2, 2, 2, 5, 4, 2 };
        MoreThanHalfNum_Solution(numbers);
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