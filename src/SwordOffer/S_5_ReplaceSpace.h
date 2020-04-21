#pragma once
#include "../BASE.h"

class S_5_ReplaceSpace : public BASE {
public:
	virtual void main()
	{
	}
    string replaceSpace(string s) 
    {
        string res;
        for (char c : s) 
        {
            if (c == ' ')
                res += "%20";
            else
                res += c;
        }
        return res;
    }
};