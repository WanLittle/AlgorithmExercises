#pragma once
#include "../BASE.h"

class S_59_MaxQueue : public BASE
{
public:
    virtual void main()
    {

    }
    class MaxQueue 
    {
    public:
        MaxQueue() 
        {

        }

        int max_value() 
        {
            if (data.empty())
                return -1;
            return max.front();
        }

        void push_back(int value) 
        {
            while (!max.empty() && max.back() < value)
            {
                max.pop_back();
            }
            max.push_back(value);
            data.push(value);
        }

        int pop_front() 
        {
            if (data.empty())
                return -1;
            int ans = data.front();
            data.pop();
            if (ans == max.front())
                max.pop_front();
            return ans;
        }
    private:
        queue<int> data;
        deque<int> max;
    };
};