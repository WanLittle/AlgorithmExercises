#pragma once
#include "../BASE.h"

/*
输入数字 `n`，按顺序打印出从 1 到最大的 n 位十进制数。
比如输入 3，则打印出 1、2、3 一直到最大的 3 位数 999。
*/
class S_17_PrintNumbers : public BASE
{
public:
    virtual void main()
    {

    }
    vector<int> res;
    vector<int> printNumbers(int n) 
    {
        if (n <= 0) return res;
        string number(n, '0');
        for (int i = 0; i <= 9; i++) //从高位到低位进行全排列
        {
            number[0] = i + '0';
            permutationNumbers(number, n, 1);
        }
        return res;
    }
    void permutationNumbers(string& number, int length, int index) {
        if (index == length) 
        {
            saveNumber(number);
            return;
        }
        else
        {
            for (int i = 0; i <= 9; i++)
            {
                number[index] = '0' + i;
                permutationNumbers(number, length, index + 1);
            }
        }
    }
    void saveNumber(string number) 
    {
        bool isBegin0 = true;
        string tempStr = "";
        auto it = number.begin();
        while (it != number.end())
        {
            if (isBegin0 && *it != '0') 
                isBegin0 = false;
            if (!isBegin0) 
            {
                tempStr += *it;
            }
            it++;
        }
        //从高位到低位全排列，要注意首字符为0时，tempStr为空，不能执行stoi
        if (!tempStr.empty()) {
            int tempNum = stoi(tempStr);
            res.push_back(tempNum);
        }
    }
};