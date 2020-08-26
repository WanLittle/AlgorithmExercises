#pragma once
#include "../../BASE.h"

class L_33_search : public BASE {
public:
	virtual void main()
	{
        vector<int> nums = { 3,1 };
        cout << search(nums, 1) << endl;
	}
    int search(vector<int>& nums, int target) {
        int n = (int)nums.size();
        if (!n) return -1;
        if (n == 1) return nums[0] == target ? 0 : -1;
        int l = 0, r = n - 1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (nums[mid] == target) return mid;
            if (nums[0] <= nums[mid]) { // mid 处于左递增区
                if (nums[l] <= target && target < nums[mid] ) {
                    r = mid - 1;
                }
                else {
                    l = mid + 1;
                }
            }
            else { // mid 处于右递增区
                if (nums[mid] < target && target <= nums[r]) {
                    l = mid + 1;
                }
                else {
                    r = mid - 1;
                }
            }
        }
        return -1;
    }
};