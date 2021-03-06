#pragma once
#include "../BASE.h"

class S_49_GetUglyNumber : public BASE {
public:
	virtual void main()
	{
        cout << GetUglyNumber_Solution(20) << endl;
        cout << GetUglyNumber_Solution_2(20) << endl;
	}
    // �ռ临�Ӷ� O(index)
    int GetUglyNumber_Solution_2(int index)
    {
        if (index <= 0)
            return 0;

        int *pUglyNumbers = new int[index];
        pUglyNumbers[0] = 1;
        int nextUglyIndex = 1;

        int *pMultiply2 = pUglyNumbers;
        int *pMultiply3 = pUglyNumbers;
        int *pMultiply5 = pUglyNumbers;

        while (nextUglyIndex < index)
        {
            int min = std::min( std::min(*pMultiply2 * 2, *pMultiply3 * 3), *pMultiply5 * 5);
            pUglyNumbers[nextUglyIndex] = min;

            while (*pMultiply2 * 2 <= pUglyNumbers[nextUglyIndex])
                ++pMultiply2;
            while (*pMultiply3 * 3 <= pUglyNumbers[nextUglyIndex])
                ++pMultiply3;
            while (*pMultiply5 * 5 <= pUglyNumbers[nextUglyIndex])
                ++pMultiply5;

            ++nextUglyIndex;
        }

        int ugly = pUglyNumbers[nextUglyIndex - 1];
        delete[] pUglyNumbers;
        return ugly;
    }


    bool isUgly(int number)
    {
        while (number % 2 == 0)
            number /= 2;
        while (number % 3 == 0)
            number /= 3;
        while (number % 5 == 0)
            number /= 5;
        return number == 1;
    }
    int GetUglyNumber_Solution(int index)
    {
        int i = 0;
        int number = 1;
        while (i < index)
        {
            if (isUgly(number))
                i++;
            ++number;
        }
        return number - 1;
    }
};