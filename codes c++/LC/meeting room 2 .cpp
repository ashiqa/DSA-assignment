/**
 * Definition of Interval:
 * classs Interval {
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

// link to problem
// https://www.lintcode.com/problem/919/

class Solution
{
public:
    /**
     * @param intervals: an array of meeting time intervals
     * @return: the minimum number of conference rooms required
     */
    int minMeetingRooms(vector<Interval> &intervals)
    {
        // Write your code here
        int n = intervals.size();
        sort(intervals.begin(), intervals.end(), [](Interval &a, Interval &b) {
            return a.start < b.start;
        });
        vector<int> res;
        for (int i = 0; i < n; ++i)
        {
            bool roomfound = false;
            for (int j = 0; j < res.size(); ++j)
            {
                if (intervals[i].start >= res[j])
                {
                    roomfound = true;
                    res[j] = intervals[i].end;
                    break;
                }
            }
            if (!roomfound)
            {
                res.push_back(intervals[i].end);
            }
        }
        return res.size();
    }
};