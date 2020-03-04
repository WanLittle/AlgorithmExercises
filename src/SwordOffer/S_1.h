#pragma once
#include "../BASE.h"

class S_1 : public BASE {
public:
	virtual void main()
	{
        cout << cutRope(8) << endl;
	}
    /*
    ��Ŀ����
    ����һ������Ϊn�����ӣ�������Ӽ�����������m�Σ�m��n����������n>1����m>1����
    ÿ�����ӵĳ��ȼ�Ϊk[0],k[1],...,k[m]������k[0]xk[1]x...xk[m]���ܵ����˻��Ƕ��٣�
    ���磬�����ӵĳ�����8ʱ�����ǰ������ɳ��ȷֱ�Ϊ2��3��3�����Σ���ʱ�õ������˻���18��
    */
    int cutRope(int number) 
    {
        vector<int> f(number + 1);
        if (number == 1) //��Ϊһ��Ҫ��
            return 1;
        else if (number == 2)
            return 1;
        else if (number == 3)
            return 2;
        else
        {
            f[1] = 1;
            for (int i = 1; i <= number; i++)
            {
                f[i] = i;
                for (int j = 1; j < i; j++)
                {
                    f[i] = std::max(f[i], f[i - j] * f[j]);
                }
            }
            return f[number];
        }
    }
};