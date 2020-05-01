#pragma once
#include "../BASE.h"

/*
求1+2+3+...+n，
要求不能使用乘除法、for、while、if、else、switch、case等关键字及条件判断语句（A?B:C）。
*/
class S_64_SumNums : public BASE {
public:
    virtual void main()
    {
    }

    /*
    // 利用构造函数
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
    int sumNums2(int n) {
        Temp::reset();
        Temp *t = new Temp[n];
        delete[] t;
        return Temp::getSUM();
    }
    */

    // 利用 && 和 递归
    int sumNums(int n)
    {
        int result = n;
        result && (result += sumNums(n - 1));
        return result;
    }
};