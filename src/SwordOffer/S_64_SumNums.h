#pragma once
#include "../BASE.h"

/*
��1+2+3+...+n��
Ҫ����ʹ�ó˳�����for��while��if��else��switch��case�ȹؼ��ּ������ж���䣨A?B:C����
*/
class S_64_SumNums : public BASE {
public:
    virtual void main()
    {
    }

    /*
    // ���ù��캯��
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

    // ���� && �� �ݹ�
    int sumNums(int n)
    {
        int result = n;
        result && (result += sumNums(n - 1));
        return result;
    }
};