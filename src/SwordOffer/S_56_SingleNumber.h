#pragma once
#include "../BASE.h"

/*
在一个数组 nums 中除一个数字只出现一次之外，其他数字都出现了三次。请找出那个只出现一次的数字。
*/
class S_56_SingleNumber : public BASE {
public:
    virtual void main()
    {
        vector<int> nums = { 3,4,3,3 };
        cout << singleNumber(nums) << endl;
    }
    int singleNumber(vector<int>& nums)
    {
        vector<int> bitSum(32, 0);
        for (int num : nums)
        {
            unsigned int bitMask = 1;
            for (int i = 0; i <= 31; ++i)
            {
                bool isone = num & bitMask;
                if (isone)
                    bitSum[i] += 1;
                bitMask = bitMask << 1;
            }
        }
        unsigned int result = 0;
        for (int i = 31; i >=0; --i)
        {
            result = result << 1;
            assert(bitSum[i] % 3 == 0 || bitSum[i] % 3 == 1);
            result += bitSum[i] % 3;
        }
        return result;
    }
};