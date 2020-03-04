#pragma once
#include "../BASE.h"

class S_58 : public BASE {
public:
	virtual void main()
	{
		string str = "student";
		cout << ReverseSentence(str) << endl;
	}
	string ReverseSentence(string str)
	{
		int length = str.size();
		Reverse(str, 0, length - 1);
		int start = 0, end = 0;
		while (end < length)
		{
			while (str[start] == ' ')
				start++;
			end = start + 1;
			if (end < length)
			{
				while (end < length && str[end] != ' ')
					end++;
				Reverse(str, start, end - 1);
				start = end;
			}
		}
		return str;
	}
	void Reverse(string &str, int start, int end)
	{
		while (start < end)
		{
			char c = str[start];
			str[start] = str[end];
			str[end] = c;
			start++;
			end--;
		}
	}
};