#pragma once
#include "../BASE.h"

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

class S_47 : public BASE {
public:
    
	virtual void main()
	{
        cout << Sum_Solution(3) << endl;
	}
    int Sum_Solution(int n) 
    {
        Temp::reset();
        Temp *t = new Temp[n];
        delete[] t;
        return Temp::getSUM();
    }
};

