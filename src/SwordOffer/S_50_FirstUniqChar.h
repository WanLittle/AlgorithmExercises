#pragma once
#include "../BASE.h"

// 在字符串 s 中找出第一个只出现一次的字符。如果没有，返回一个单空格。
class S_50_FirstUniqChar : public BASE {
public:
	virtual void main()
	{
	}
    char firstUniqChar(string s) 
    {
        vector<int> table(256, 0);
        for (char c : s)
        {
            table[c]++;
        }
        for (char c : s)
        {
            if (table[c] == 1)
                return c;
        }
        return ' '; // '/0'无法通过leetcode
    }
};