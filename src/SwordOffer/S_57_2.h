#pragma once
#include "../BASE.h"

class S_57_2 : public BASE {
public:
	virtual void main()
	{
	}
	vector<vector<int> > FindContinuousSequence(int sum) 
	{
		vector<vector<int> > results;
		vector<int> result;
		if (sum < 3) return results;
		int start = 1, end = 2;
		int currSum = start + end;
		int middle = sum / 2;
		while (start <= middle)
		{
			if (currSum < sum)
			{
				end++;
				currSum = currSum + end;
			}
			else if (currSum == sum)
			{
				result.clear();
				for (int i = start; i <= end; i++)
					result.push_back(i);
				results.push_back(result);
				end++;
				currSum = currSum + end;
			}
			else
			{
				currSum = currSum - start;
				start++;
			}
		}
		return results;
	}
};