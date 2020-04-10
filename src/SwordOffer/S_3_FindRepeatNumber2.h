#pragma once
#include "../BASE.h"

/*
��һ������Ϊ n+1 ������ nums ����������ֶ��� 0��n-1 �ķ�Χ�ڡ�
���ҳ�����������һ���ظ������֡�
*/
class S_3_FindRepeatNumber2 : public BASE {
public:
    virtual void main()
    {
        vector<int> nums = { 0, 1, 2, 0, 4, 5, 6, 7, 8, 9 };
        cout << findRepeatNumber(nums) << endl;
    }

    int findRepeatNumber(vector<int>& nums)
    {
        if (nums.empty()) return -1;
        int start = 0;
        int end = nums.size() - 1;
        while (start <= end)
        {
            int mid = (start + end) / 2;
            int count = count_if(nums.begin(), nums.end(),
                [mid, start](int num) { return num <= mid && num >= start; });
            if (start == end)
                return start;
            if (count > (mid - start + 1))
                end = mid;
            else
                start = mid + 1;
        }
        return -1;
    }
};