class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.empty()) return 0;

        int result = 0;
        sort(intervals.begin(), intervals.end(), \
                [](const vector<int>& a, const vector<int>& b) {
                if (a[1] == b[1]) // If second values are equal, sort by first value
                    return a[0] > b[0];
                return a[1] < b[1];
            });
        
        int now = intervals[0][1];
        for(int i=1; i<intervals.size(); i++) {
            if(now<=intervals[i][0]) {
                now = intervals[i][1];
            }
            else {
                result++;
                continue;
            }
        }
        return result;
    }
};
