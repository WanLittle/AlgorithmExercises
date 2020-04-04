#pragma once
#include "../BASE.h"

// 在数组中的两个数字，如果前面一个数字大于后面的数字，则这两个数字组成一个逆序对。输入一个数组，求出这个数组中的逆序对的总数。
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
            if (nums[i] > nums[j]) //逆序
            {
                global_count = global_count + (mid - i + 1); // 归并排序添加的唯一一行代码。
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