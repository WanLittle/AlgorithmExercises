#pragma once
#include "../BASE.h"

// ����n���������ҳ�������С��K��������������4,5,1,6,2,7,3,8��8�����֣�����С��4��������1,2,3,4,��
class S_40_GetKLeastNumbers : public BASE {
public:
	virtual void main()
	{
	}

    // �ô󶥶�ʵ����ѡ������Ը��ӣ�����ʹ�� STL ��� multiset �ײ��Ǻ����
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

    // ����
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