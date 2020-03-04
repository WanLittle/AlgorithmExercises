#pragma once
#include "../BASE.h"

class S_57 : public BASE {
public:
	virtual void main()
	{
	}
	vector<int> FindNumbersWithSum(vector<int> array, int sum) 
	{
		vector<int> result;
		int length = array.size();
		int start = 0, end = length - 1;
		int num1, num2;
		bool find = false;
		while (start < end)
		{
			if (array[start] + array[end] < sum)
			{
				start++;
			}
			else if (array[start] + array[end] == sum)
			{
				if (!find)
				{
					num1 = array[start];
					num2 = array[end];
					find = true;
				}
				else 
				{
					if (array[start] * array[end] < num1 * num2)
					{
						num1 = array[start];
						num2 = array[end];
					}
				}
				start++;
				end--;
			}
			else
			{
				end--;
			}
		}
		if (find)
		{
			result.push_back(num1);
			result.push_back(num2);
		}
		return result;
	}
};