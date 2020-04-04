#pragma once
#include "../BASE.h"

// ���ַ��� s ���ҳ���һ��ֻ����һ�ε��ַ������û�У�����һ�����ո�
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
        return ' '; // '/0'�޷�ͨ��leetcode
    }
};