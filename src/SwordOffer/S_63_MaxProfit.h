#pragma once
#include "../BASE.h"

class S_63_MaxProfit : public BASE
{
public:
    virtual void main()
    {

    }
    int maxProfit(vector<int>& prices) 
    {
        int profit = 0;
        int min_price = INT_MAX;
        for (int i = 0; i < prices.size(); ++i) 
        {
            min_price = min(min_price, prices[i]);
            profit = max(profit, prices[i] - min_price);
        }
        return profit;
    }
};