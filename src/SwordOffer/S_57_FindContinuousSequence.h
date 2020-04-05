#pragma once
#include "../BASE.h"

/*
����һ�������� target ��������к�Ϊ target ���������������У����ٺ�������������

�����ڵ�������С�������У���ͬ���а����׸����ִ�С�������С�
*/
class S_57_FindContinuousSequence : public BASE {
public:
	virtual void main()
	{
	}
    vector<vector<int>> findContinuousSequence(int target) 
    {
        int left = 1; // �������ڵ���߽�
        int right = 1; // �������ڵ��ұ߽�
        int sum = 0; // �������������ֵĺ�
        vector<vector<int>> res;
        while (left <= target / 2) 
        {
            if (sum < target) // �ұ߽�����
            {
                sum += right;
                right++;
            }
            else if (sum > target) // ��߽�����
            {
                sum -= left;
                left++;
            }
            else // ��¼���
            {
                vector<int> arr;
                for (int k = left; k < right; k++) 
                {
                    arr.push_back(k);
                }
                res.push_back(arr);
                // ��߽������ƶ�
                sum -= left;
                left++;
            }
        }
        return res;
    }
};