#pragma once
#include "../BASE.h"

/*
把字符串转换成整数
*/
class S_67_StrToInt : public BASE
{
public:
    virtual void main()
    {

    }
    int strToInt(string str) 
    {
        if (str.size() == 0) return 0;
        int i = 0;
        long ans = 0;
        bool negative = false;

        while (str[i] == ' ') i++;
        if (str[i] == '-')
        {
            negative = true;
            i++;
        }
        else if (str[i] == '+')
            i++;

        for (; i < str.size(); i++)
        {
            if (str[i] >= '0' && str[i] <= '9')
            {
                ans = ans * 10 + (str[i] - '0');
                if (ans > INT_MAX && negative) 
                    return INT_MIN;
                if (ans > INT_MAX && !negative) 
                    return INT_MAX;
            }
            else
                break;
        }

        return negative ? -ans : ans;
    }
};