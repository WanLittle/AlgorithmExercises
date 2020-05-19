#pragma once
#include "../BASE.h"

class S_38_Permutation : public BASE {
public:
	virtual void main()
	{

	}
    vector<string> permutation(string s) 
    {
        set<string> res;
        help(s, res, 0);
        return vector<string>(res.begin(), res.end());
    }
    void help(string s, set<string>& res, int start)
    {
        if (start >= s.size())
        {
            res.insert(s);
            return;
        }
        for (int i = start; i < s.size(); ++i)
        {
            swap(s[i], s[start]);
            help(s, res, start + 1);
            swap(s[i], s[start]);
        }
    }
};