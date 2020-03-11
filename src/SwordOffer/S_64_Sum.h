#pragma once
#include "../BASE.h"

/*
class Temp
{
public:
    static int N;
    static int SUM;
    Temp()
    {
        N++;
        SUM = SUM + N;
    }
    static void reset()
    {
        N = 0;
        SUM = 0;
    }
    static int getSUM() { return SUM; }
};
int Temp::N = 0;
int Temp::SUM = 0;
*/
class S_68_Sum : public BASE {
public:
    virtual void main()
    {
    }
    // 利用构造函数
    /*
    int Sum_Solution2(int n) {
        Temp::reset();
        Temp *t = new Temp[n];
        delete[] t;
        return Temp::getSUM();
    }
    */

    // 利用 && 和 递归
    int Sum_Solution(int n)
    {
        int result = n;
        result && (result += Sum_Solution(n - 1));
        return result;
    }
};