#pragma once
#include "../BASE.h"

/*(ST b)
����һ���ַ������У�������ĸ�������Լ��ո������ֵĴ��������ɶ��ٸ� "Good"
�ַ������ִ�Сд��ÿ���ַ�ֻ��ʹ��һ�Σ��Ҳ��ܵ����ַ�˳��

ʾ����
ggoodood
0

Goo23good Goodd
2

123 GoodoodGGoooddjfhjdGGooo3dkdgggGood0123 \n
5
*/
class V_good_count : public BASE 
{
public:
	virtual void main()
	{
        string str;
        //str = "123 GoodoodGGoooddjfhjdGGooo3dkdgggGood0123 \n";
        getline(cin, str);
        cout << good_count(str) << endl;
    }
    int good_count(string &s)
    {
        int res = 0;
        vector<int> g_pos_arr = vector<int>();
        int g_t = -1;
        vector<int> o_pos_arr = vector<int>();
        int o_t = -1;
        vector<int> d_pos_arr = vector<int>();
        int d_t = -1;
        for (int i = 0; i < s.length(); ++i)
        {
            if (s[i] == 'G')
                g_pos_arr.push_back(i);
            else if (s[i] == 'o')
                o_pos_arr.push_back(i);
            else if (s[i] == 'd')
                d_pos_arr.push_back(i);
        }
        while (true)
        {
            ++g_t;
            if (g_t >= g_pos_arr.size())
                return res;

            ++o_t;
            while (o_t < o_pos_arr.size() && o_pos_arr[o_t] < g_pos_arr[g_t])
                ++o_t;
            ++o_t;
            if (o_t >= o_pos_arr.size())
                return res;

            ++d_t;
            while (d_t < d_pos_arr.size() && d_pos_arr[d_t] < o_pos_arr[o_t])
                ++d_t;
            if (d_t >= d_pos_arr.size())
                return res;
            
            ++res;
        }
    }
};