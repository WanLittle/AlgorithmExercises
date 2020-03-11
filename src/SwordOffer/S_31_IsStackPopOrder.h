#pragma once
#include "../BASE.h"

/*
���������������У���һ�����б�ʾջ��ѹ��˳�����жϵڶ��������Ƿ����Ϊ��ջ�ĵ���˳��
����ѹ��ջ���������־�����ȡ�
��������1,2,3,4,5��ĳջ��ѹ��˳������4,5,3,2,1�Ǹ�ѹջ���ж�Ӧ��һ���������У���4,3,5,1,2�Ͳ������Ǹ�ѹջ���еĵ������С�
��ע�⣺���������еĳ�������ȵģ�
*/
class S_31_IsStackPopOrder : public BASE {
public:
	virtual void main()
	{
	}

    bool IsPopOrder(vector<int> pushV, vector<int> popV)
    {
        int length1 = pushV.size(), length2 = popV.size();
        if (length1 != length2)
            return false;
        stack<int> myStack;
        int p = 0;
        for (int i = 0; i < length1; i++)
        {
            while (myStack.empty() || myStack.top() != popV[i])
            {
                myStack.push(pushV[p++]);
                if (p > length1)
                {
                    return false;
                }
            }
            myStack.pop();
        }
        if (myStack.empty())
            return true;
        else
            return false;
    }

};