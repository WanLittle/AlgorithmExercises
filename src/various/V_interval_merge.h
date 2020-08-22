#pragma once
#include "../BASE.h"

/*(WY 1)
����һϵ�����䣬��ʵ��һ������������Щ����ϲ���
����[1,4]��[2,6]��[9,10]��[12,13]���ĸ����䣬�ϲ����Ϊ[1,6]��[9,10]��[12,13]��
��Ҫע������������Ҳ��Ϊ�ǿ��Ժϲ��ģ�����[1,2]��[2,3]���Ժϲ�Ϊ [1,3]��
*/
class V_interval_merge : public BASE {
public:
    virtual void main()
    {
        //vector<Interval> intervals = {{1, 4}, { 2, 6 }, { 9, 10 }, { 12, 13 }};
        vector<Interval> intervals = { {1,2}, {2,3} };
        auto result = merge(intervals);
        for (auto i : result)
        {
            cout << i.start << " " << i.end << endl;
        }
        cin.get();
    }
    struct Interval {
        int start;
        int end;
        Interval(int _start, int _end) : start(_start), end(_end) { }
    };

    /*
    �Ȱ��� start ����
    Ȼ���ǰ�����ж�����Ԫ���Ƿ��ཻ���ཻ�� merge
    */
    std::vector<Interval> merge(std::vector<Interval>& intervals)
    {
        if (intervals.size() <= 1)
        {
            return intervals;
        }

        vector<Interval> result;
        sort(intervals.begin(), intervals.end(), [](Interval a, Interval b) { return a.start < b.start; });
        Interval temp(intervals[0].start, intervals[0].end);

        int i = 0;
        while (i < intervals.size())
        {
            temp.start = intervals[i].start;
            temp.end = intervals[i].end;
            while (i < intervals.size())
            {
                if (i < intervals.size() - 1 && temp.end >= intervals[i + 1].start) // ���ཻ
                {
                    if (temp.end < intervals[i + 1].end)
                    {
                        temp.end = intervals[i + 1].end;
                    }
                    ++i;
                }
                else // �ཻ
                {
                    ++i;
                    break;
                }
            }
            result.push_back(temp);
        }
        return result;
    }
};