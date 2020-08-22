#pragma once
#include "../BASE.h"

/*(WY 1)
给定一系列区间，请实现一个函数，将这些区间合并。
例如[1,4]、[2,6]、[9,10]、[12,13]这四个区间，合并结果为[1,6]、[9,10]、[12,13]。
需要注意连续的区间也认为是可以合并的，例如[1,2]、[2,3]可以合并为 [1,3]。
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
    先按照 start 排序
    然后从前往后，判断相邻元素是否相交，相交则 merge
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
                if (i < intervals.size() - 1 && temp.end >= intervals[i + 1].start) // 不相交
                {
                    if (temp.end < intervals[i + 1].end)
                    {
                        temp.end = intervals[i + 1].end;
                    }
                    ++i;
                }
                else // 相交
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