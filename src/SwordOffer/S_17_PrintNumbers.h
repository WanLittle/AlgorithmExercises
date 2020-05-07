#pragma once
#include "../BASE.h"

/*
�������� `n`����˳���ӡ���� 1 ������ n λʮ��������
�������� 3�����ӡ�� 1��2��3 һֱ������ 3 λ�� 999��
*/
class S_17_PrintNumbers : public BASE
{
public:
    virtual void main()
    {

    }
    vector<int> res;
    vector<int> printNumbers(int n) 
    {
        if (n <= 0) return res;
        string number(n, '0');
        for (int i = 0; i <= 9; i++) //�Ӹ�λ����λ����ȫ����
        {
            number[0] = i + '0';
            permutationNumbers(number, n, 1);
        }
        return res;
    }
    void permutationNumbers(string& number, int length, int index) {
        if (index == length) 
        {
            saveNumber(number);
            return;
        }
        else
        {
            for (int i = 0; i <= 9; i++)
            {
                number[index] = '0' + i;
                permutationNumbers(number, length, index + 1);
            }
        }
    }
    void saveNumber(string number) 
    {
        bool isBegin0 = true;
        string tempStr = "";
        auto it = number.begin();
        while (it != number.end())
        {
            if (isBegin0 && *it != '0') 
                isBegin0 = false;
            if (!isBegin0) 
            {
                tempStr += *it;
            }
            it++;
        }
        //�Ӹ�λ����λȫ���У�Ҫע�����ַ�Ϊ0ʱ��tempStrΪ�գ�����ִ��stoi
        if (!tempStr.empty()) {
            int tempNum = stoi(tempStr);
            res.push_back(tempNum);
        }
    }
};