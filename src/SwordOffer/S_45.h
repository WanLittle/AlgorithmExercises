#pragma once
#include "../BASE.h"

class S_45 : public BASE {
public:
	virtual void main()
	{
        cout << LastRemaining_Solution(8, 4) << endl;
	}
    int LastRemaining_Solution(int n, int m)
    {
        if (n < 1 || m < 1)
            return -1;
        list<int> circle;
        for (int i = 0; i < n; i++)
        {
            circle.push_back(i);
        }
        list<int>::iterator current = circle.begin();
        while (circle.size() > 1)
        {
            for (int i = 0; i < m - 1; i++)
            {
                current++;
                if (current == circle.end())
                    current = circle.begin();
            }
            auto next = ++current;
            if (next == circle.end())
                next = circle.begin();
            current--;
            circle.erase(current);
            current = next;
        }
        return circle.front();
    }
};