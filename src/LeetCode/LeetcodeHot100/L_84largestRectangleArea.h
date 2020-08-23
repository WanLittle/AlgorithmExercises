#pragma once
#include "../../BASE.h"


class L_84largestRectangleArea : public BASE {
public:
	virtual void main()
	{
        vector<int> h = { 2,1,5,6,2,3 };
        cout << largestRectangleArea(h) << endl;
	}

    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> left(n, -1), right(n, -1);
        stack<int> monostack;
        for (int i = 0; i < n; ++i) {
            while (!monostack.empty() && heights[monostack.top()] >= heights[i]) {
                monostack.pop();
            }
            left[i] = monostack.empty() ? -1 : monostack.top();
            monostack.push(i);
        }
        monostack = stack<int>();
        for (int i = n - 1; i >= 0; --i) {
            while (!monostack.empty() && heights[monostack.top()] >= heights[i]) {
                monostack.pop();
            }
            right[i] = monostack.empty() ? n : monostack.top();
            monostack.push(i);
        }
        int result = 0;
        for (int i = 0; i < n; ++i) {
            result = max(result, (right[i] - left[i] - 1) * heights[i]);
        }
        return result;
    }
};