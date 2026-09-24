class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int i = 0,j =1, count = 0;

        while (j <intervals.size()) {
            if (intervals[i][1]<= intervals[j][0]) {
                i = j;
                j++;
            }else{
                if (intervals[j][1]> intervals[i][1]) {
                    count++;
                    j++;
                }else{
                    count++;
                    i = j;
                    j++;
                }
            }
        }
        return count;
    }
};