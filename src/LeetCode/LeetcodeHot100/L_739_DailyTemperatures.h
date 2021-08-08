#pragma once
#include "../../BASE.h"


class L_739_DailyTemperatures : public BASE {
public:
	virtual void main()
	{
	}
    vector<int> dailyTemperatures(vector<int>& T) {
        vector<int> result(T.size(), 0);
        stack<int> monostack;
        for (int i = 0; i < T.size(); ++i) {
            while (!monostack.empty() && T[monostack.top()] < T[i]) {
                result[monostack.top()] = i;
                monostack.pop();
            }
            monostack.push(i);
        }
        return result;
    }
};