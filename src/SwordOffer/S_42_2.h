#pragma once
#include "../BASE.h"

class S_42_2 : public BASE {
public:
    virtual void main()
    {
        string str("abcdefg");
        LeftRotateString(str, 2);
    }
    string LeftRotateString(string str, int n)
    {
        if (n < 0 || n > str.size())
            return str;
        Reverse(str, 0, n - 1);
        Reverse(str, n, str.size() - 1);
        Reverse(str, 0, str.size() - 1);
        return str;
    }
    void Reverse(string &str, int start, int end)
    {
        while (start < end)
        {
            char c = str[start];
            str[start] = str[end];
            str[end] = c;
            start++;
            end--;
        }
    }
};