#pragma once
#include "../BASE.h"

class S_61 : public BASE {
public:
	virtual void main()
	{
		string str = "I am a student.";
		cout << ReverseSentence(str) << endl;
	}
	string ReverseSentence(string str) 
	{
		int length = str.size();
		Reverse(str, 0, length - 1);
		int start = 0, end = 0;
		while(end < length)
		{
			while (str[start] == ' ')
				start++;
			end = start + 1;
			while (str[end] == ' ')
				end++;
			Reverse(str, start, end - 1);
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
		}
	}
};