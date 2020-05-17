#pragma once
#include "../BASE.h"

class S_45_MinNumber : public BASE {
public:
	virtual void main()
	{
	}
    string minNumber(vector<int>& nums) 
    {
        vector<string> snums;
        string res;
        for (int num : nums)
        {
            snums.push_back(to_string(num));
        }
        sort(snums.begin(), snums.end(), [](string a, string b) { return a + b < b + a; });
        for (const string& snum : snums)
        {
            res += snum;
        }
        return res;
    }
};