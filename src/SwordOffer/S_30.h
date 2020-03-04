#pragma once
#include "../BASE.h"

class S_30 : public BASE {
public:
	virtual void main()
	{
        vector<int> numbers = { 2,3,4,5,6,1 };
        GetLeastNumbers_Solution(numbers, 3);
	}
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k)
    {
        std::multiset<int, greater<int>> leastNumber;
        vector<int> result;
        if (input.size() < k)
            return result;
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
};