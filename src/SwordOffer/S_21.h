#pragma once
#include "../BASE.h"

class S_21 : public BASE {
public:
	virtual void main()
	{
	}
private:
    stack<int> m_stack;
    stack<int> min_stack;
public:
    void push(int value) {
        m_stack.push(value);
        if (min_stack.empty())
        {
            min_stack.push(value);
        }
        else
        {
            if (value > min_stack.top())
                min_stack.push(min_stack.top());
            else
                min_stack.push(value);
        }
    }
    void pop() {
        m_stack.pop();
        min_stack.pop();
    }
    int top() {
        return m_stack.top();
    }
    int min() {
        return min_stack.top();
    }
};