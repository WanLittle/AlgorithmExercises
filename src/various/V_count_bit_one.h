#pragma once
#include "../BASE.h"


class V_count_bit_one : public BASE {
public:
	virtual void main()
	{
        cout << count_bit_one(0x04) << endl; //1
        cout << count_bit_one(0xff) << endl; //8
	}
    unsigned int count_bit_one(unsigned int num)
    {
        unsigned int count = 0;
        for (size_t i = 0; i < 8 * sizeof(num); ++i)
        {
            if (num & 1 << i)
                count++;
        }
        return count;
    }
};