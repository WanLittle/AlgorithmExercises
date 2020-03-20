#pragma once
#include "../BASE.h"

// �������е���λ��
class S_41_MedianFinder : public BASE {
public:
	virtual void main()
	{
	}
    class MedianFinder 
    {
    public:
        priority_queue<int> maxHeap; //�����, ����������С�Ĳ���
        priority_queue<int, vector<int>, greater<int>> minHeap; //С���ѣ�����ұ����ݴ�Ĳ���
        int count = 0;

    public:
        void addNum(int num)
        {
            if (count & 1) //������Ԫ��,���뵽С����
            {
                if (maxHeap.size() > 0 && num < maxHeap.top())
                {
                    maxHeap.push(num);
                    num = maxHeap.top();
                    maxHeap.pop();
                }
                minHeap.push(num);
            }
            else // ���뵽�����
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