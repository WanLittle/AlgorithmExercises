#pragma once
#include "../BASE.h"

class S_53 : public BASE {
public:
	virtual void main()
	{
		vector<int> data = { 1,2,3,3,3,3,4,5 };
		int k = 3;
		cout << GetNumberOfK(data, k) << endl;
	}
	int GetNumberOfK(vector<int> data, int k) 
	{
		int length = data.size();
		int number = 0;
		if (length > 0)
		{
			int first = GetFirstK(data, length, k, 0, length - 1);
			int last = GetLastK(data, length, k, 0, length - 1);
			if (first != -1 && last != -1)
				number = last - first + 1;
		}
		return number;
	}
	int GetFirstK(vector<int> data, int length, int k, int start, int end)
	{
		if (start > end) return -1;
		int middleIndex = (start + end) / 2;
		int middleData = data[middleIndex];
		if (middleData == k)
		{
			if (middleIndex == 0 ||
				(middleIndex > 0 && data[middleIndex - 1] != k))
				return middleIndex;
			else
				end = middleIndex - 1;
		}
		else if (middleData > k)
			end = middleIndex - 1;
		else
			start = middleIndex + 1;
		return GetFirstK(data, length, k, start, end);
	}
	int GetLastK(vector<int> data, int length, int k, int start, int end)
	{
		if (start > end) return -1;
		int middleIndex = (start + end) / 2;
		int middleData = data[middleIndex];
		if (middleData == k)
		{
			if (middleIndex == length - 1 ||
				(middleIndex < length - 1 && data[middleIndex + 1] != k))
				return middleIndex;
			else
				start = middleIndex + 1;
		}
		else if (middleData > k)
			end = middleIndex - 1;
		else
			start = middleIndex + 1;
		return GetLastK(data, length, k, start, end);
	}
};