#pragma once
#include "../BASE.h"

// �������е��������֣����ǰ��һ�����ִ��ں�������֣����������������һ������ԡ�����һ�����飬�����������е�����Ե�������
class S_51_ReversePairs : public BASE {
public:
	virtual void main()
	{
        vector<int> nums = { 7,5,6,4 };
        cout << reversePairs(nums) << endl;
	}
    int reversePairs(vector<int>& nums) 
    {
        int global_count = 0;
        vector<int> copyarr(nums.size(), 0);
        merge_sort(nums, copyarr, 0, nums.size() - 1, global_count);
        return global_count;
    }
    void merge_sort(vector<int>& nums, vector<int>& copyarr, int left, int right, int &global_count)
    {
        if (left >= right) return;
        int mid = (left + right) / 2;
        merge_sort(nums, copyarr, left, mid, global_count);
        merge_sort(nums, copyarr, mid + 1, right, global_count);
        int i = left, j = mid + 1, k = left;
        while (i <= mid && j <= right) 
        {
            if (nums[i] > nums[j]) //����
            {
                global_count = global_count + (mid - i + 1); // �鲢������ӵ�Ψһһ�д��롣
                copyarr[k++] = nums[j++];
            }
            else 
            {
                copyarr[k++] = nums[i++];
            }
        }
        if (i <= mid)
            copy(nums.begin() + i, nums.begin() + mid + 1, copyarr.begin() + k);
        if (j <= right) 
            copy(nums.begin() + j, nums.begin() + right + 1, copyarr.begin() + k);
        copy(copyarr.begin() + left, copyarr.begin() + right + 1, nums.begin() + left);
    }
};