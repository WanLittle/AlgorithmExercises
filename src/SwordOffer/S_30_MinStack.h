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
        minStack.min();   //-- > 返回 - 3.
        minStack.pop();
        minStack.top();   //-- > 返回 0.
        minStack.min();   //-- > 返回 -2.
	}
    /*
    使用一个辅助栈，s_min，在每次s_data压入数据后，与s_min的top进行比较，如果比s_min当前的top的大，
    则将该数据压入到s_min中，如果s_min的top更大，则将top压入到s_min中
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