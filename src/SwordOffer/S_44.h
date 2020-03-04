#pragma once
#include "../BASE.h"

class S_44 : public BASE {
public:
	virtual void main()
	{
        vector<int> numbers = { 0,3,1,6,4};
        cout << IsContinuous(numbers) << endl;
	}
    bool IsContinuous(vector<int> numbers) 
    {
        if (numbers.size() < 1)
            return false;
        sort(numbers.begin(), numbers.end());
        int zeroCount = 0;
        int gap = 0;
        for (int i = 0; i < numbers.size(); i++)
        {
            if (numbers[i] == 0) 
                zeroCount++;
            else
            {
                if(i == zeroCount)
                    continue;
                
                if (numbers[i] == numbers[i - 1])
                        return false;

                gap += numbers[i] - numbers[i - 1] - 1;
            }
        }
        if (zeroCount >= gap)
            return true;
        return false;
    }
};