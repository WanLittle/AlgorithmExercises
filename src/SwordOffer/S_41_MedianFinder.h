#pragma once
#include "../BASE.h"

// 数据流中的中位数
class S_41_MedianFinder : public BASE {
public:
	virtual void main()
	{
	}
    class MedianFinder 
    {
    public:
        priority_queue<int> maxHeap; //大根堆, 存放左边数据小的部分
        priority_queue<int, vector<int>, greater<int>> minHeap; //小根堆，存放右边数据大的部分
        int count = 0;

    public:
        void addNum(int num)
        {
            if (count & 1) //奇数个元素,插入到小根堆
            {
                if (maxHeap.size() > 0 && num < maxHeap.top())
                {
                    maxHeap.push(num);
                    num = maxHeap.top();
                    maxHeap.pop();
                }
                minHeap.push(num);
            }
            else // 插入到大根堆
            {
                if (minHeap.size() > 0 && num > minHeap.top())
                {
                    minHeap.push(num);
                    num = minHeap.top();
                    minHeap.pop();
                }
                maxHeap.push(num);
            }
            ++count;
        }

        double findMedian()
        {
            if (minHeap.empty() && maxHeap.empty())
                return INT_MIN * 1.0;
            return count & 1 ? maxHeap.top() : (maxHeap.top() + minHeap.top()) * 0.5;
        }

    };
};