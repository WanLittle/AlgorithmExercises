#pragma once
#include "../BASE.h"

class S_30_MinStack : public BASE {
public:
	virtual void main()
	{
        MinStack minStack;
        minStack.push(-2);
        minStack.push(0);
        minStack.push(-3);
        minStack.min();   //-- > ���� - 3.
        minStack.pop();
        minStack.top();   //-- > ���� 0.
        minStack.min();   //-- > ���� -2.
	}
    /*
    ʹ��һ������ջ��s_min����ÿ��s_dataѹ�����ݺ���s_min��top���бȽϣ������s_min��ǰ��top�Ĵ�
    �򽫸�����ѹ�뵽s_min�У����s_min��top������topѹ�뵽s_min��
    */
    class MinStack
    {
    private:
        stack<int> s_min;
        stack<int> s_data;
    public:
        /** initialize your data structure here. */
        MinStack()
        {

        }

        void push(int x)
        {
            s_data.push(x);
            if (s_min.size() <= 0) s_min.push(x);
            else
            {
                if (x <= s_min.top())
                    s_min.push(x);
                else
                    s_min.push(s_min.top());
            }
        }

        void pop()
        {
            if (s_data.size() == 0) return;
            s_data.pop();
            s_min.pop();
        }

        int top()
        {
            return s_data.top();
        }

        int min()
        {
            return s_min.top();
        }
    };
};