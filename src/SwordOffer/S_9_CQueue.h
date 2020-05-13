#pragma once
#include "../BASE.h"

class S_9_CQueue : public BASE {
public:
	virtual void main()
	{
	}
    class CQueue 
    {
    public:
        stack<int> stack1;
        stack<int> stack2;
        CQueue() {}

        void appendTail(int value) 
        {
            stack1.push(value);
        }

        int deleteHead() 
        {
            int ans = -1;
            if (!stack2.empty())
            {
                ans = stack2.top();
                stack2.pop();
            }
            else if (!stack1.empty())
            {
                while (!stack1.empty())
                {
                    stack2.push(stack1.top());
                    stack1.pop();
                }
                ans = stack2.top();
                stack2.pop();
            }
            return ans;
        }
    };
};