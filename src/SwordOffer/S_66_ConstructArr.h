#pragma once
#include "../BASE.h"

/*
给定一个数组 A[0,1,…,n-1]，请构建一个数组 B[0,1,…,n-1]，
其中 B 中的元素 B[i]=A[0]×A[1]×…×A[i-1]×A[i+1]×…×A[n-1]。
不能使用除法。
*/
class S_66_ConstructArr : public BASE
{
public:
    virtual void main()
    {

    }
    vector<int> constructArr(vector<int>& a) 
    {
        int n = a.size();
        vector<int> res(n, 1);
        for (int i = 1; i < n; ++i) 
        {
            res[i] = res[i - 1] * a[i - 1];
        }
        int temp = 1;
        for (int i = n - 2; i >= 0; --i) 
        {
            temp *= a[i + 1];
            res[i] *= temp;
        }
        return res;
    }
};