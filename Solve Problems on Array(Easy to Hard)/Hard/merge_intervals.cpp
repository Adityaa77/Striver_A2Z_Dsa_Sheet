/ 🔁 Approach 1: Slightly Less Optimal but Correct
// ✅ Time: O(N log N + N^2) due to nested loop in worst case
// ✅ Space: O(N) for output vector
// 👉 Idea: Sort intervals, skip covered ones, expand current interval by checking all overlaps
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        sort(intervals.begin(), intervals.end());  // Sort by starting times
        int n = intervals.size();
        
        for(int i = 0; i < n; i++) {
            int start = intervals[i][0];
            int end = intervals[i][1];

            // If this interval is completely covered by the last one added, skip
            if(!ans.empty() && end <= ans.back()[1]) continue;

            // Check for all future intervals that overlap
            for(int j = i + 1; j < n; j++) {
                if(intervals[j][0] <= end) {
                    end = max(end, intervals[j][1]);
                } else {
                    break;
                }
            }

            // Push the merged interval
            ans.push_back({start, end});
        }

        return ans;
    }
};

// 🚀 Approach 2: Optimal Merge Intervals
// ✅ Time: O(N log N) — due to sorting
// ✅ Space: O(N) — for the output vector
// 🔥 Most efficient and cleanest approach
// 👉 Idea: After sorting, only merge if current start <= last end in result
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<vector<int>> ans;
        sort(intervals.begin(), intervals.end());  // Sort based on start time

        for(int i = 0; i < n; i++) {
            // If no overlap, simply push the interval
            if(ans.empty() || intervals[i][0] > ans.back()[1]) {
                ans.push_back(intervals[i]);
            }
            // If overlap exists, merge with the last interval
            else {
                ans.back()[1] = max(ans.back()[1], intervals[i][1]);
            }
        }

        return ans;
    }
};
