#pragma once
#include "../BASE.h"

class S_21_ReOrderArray : public BASE {
public:
	virtual void main()
	{
	}

    // 会变动相对顺序
    // 时间复杂度 O(n)
    // 空间复杂度 O(1)
    void reOrderArray(vector<int> &array) 
    {
        int len = array.size();
        if (len < 2) return;
        int l = 0, r = len - 1;
        while (l < r)
        {
            while ((array[l] & 0x1) == 1 && l < r)
                l++;
            while ((array[r] & 0x1) != 1 && l < r)
                r--;
            if (l < r)
            {
                int t = array[l];
                array[l] = array[r];
                array[r] = t;
            }
        }
    }

};