/**
 * AUTHOR: Shrey Shah
 * Language: Cpp
 * LeetCode Question No: 56

 * Given a collection of intervals, merge all overlapping intervals.

 * For example,
 * Given [1,3],[2,6],[8,10],[15,18],
 * return [1,6],[8,10],[15,18].
 
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
bool myfunction (Interval first, Interval second) {
    return first.start < second.start;
} 
 
class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval> mergeResult;
        int length = intervals.size();
        if (length == 0 || length == 1) {
            return intervals;
        }
        
        sort(intervals.begin(), intervals.end(), myfunction);
        
        int mergeStart = intervals[0].start;
        int mergeEnd = intervals[0].end;
        for (int i = 1 ; i < length ; i++) {
            if (mergeEnd >= intervals[i].start) {
                mergeEnd = max(mergeEnd, intervals[i].end);
            } else {
                mergeResult.push_back(Interval(mergeStart, mergeEnd));
                mergeStart = intervals[i].start;
                mergeEnd = intervals[i].end;
            }
            // Edge Case.     
            if (i == length - 1) {
                mergeResult.push_back(Interval(mergeStart, mergeEnd));
            }
        }
        return mergeResult;
    }
};
