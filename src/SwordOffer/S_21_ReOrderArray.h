#pragma once
#include "../BASE.h"

class S_21_ReOrderArray : public BASE {
public:
	virtual void main()
	{
	}

    // ��䶯���˳��
    // ʱ�临�Ӷ� O(n)
    // �ռ临�Ӷ� O(1)
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