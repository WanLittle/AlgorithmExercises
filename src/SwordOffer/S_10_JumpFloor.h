#pragma once
#include "../BASE.h"

// ÇàÍÜÌøÌ¨½×
class S_10_JumpFloor : public BASE {
public:
    virtual void main()
    {
    }

    int jumpFloor(int number) 
    {
        int f[3] = { 0, 1, 2 };
        if (number < 3)
            return f[number];
        int f_n, f_n1 = f[2], f_n2 = f[1];
        for (int i = 3; i <= number; i++)
        {
            f_n = f_n1 + f_n2;
            f_n2 = f_n1;
            f_n1 = f_n;
        }
        return f_n;
    }
};