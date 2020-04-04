#pragma once
#include "../BASE.h"

// һ������Ϊn-1�ĵ������������е��������ֶ���Ψһ�ģ�����ÿ�����ֶ��ڷ�Χ0��n-1֮�ڡ�
// �ڷ�Χ0��n-1�ڵ�n������������ֻ��һ�����ֲ��ڸ������У����ҳ�������֡�
class S_53_MissingNumber : public BASE 
{
public:
    virtual void main()
    {
        vector<int> nums = { 0,1,2,3,4,5,6,7,9 };
        cout << missingNumber(nums) << endl;
        // {0}-�����1
    }
    int missingNumber(vector<int>& nums)
    {
        int low = 0;
        int high = nums.size() - 1;
        while (low <= high)
        {
            int mid = (low + high) * 0.5f;
            if (nums[mid] == mid)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return low;
    }
};