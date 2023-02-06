// Brute Force:
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int rowsize = intervals.size();

        // step 1: ensure the array is sorted
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> ans;

        // step 2: for each interval we will compare it to every other interval
        for(int i = 0; i < rowsize; i++) {
            int start = intervals[i][0];
            int end = intervals[i][1];

            // if the interval already exists 
            // & since we compared the whole vector means this interval is merged 
            // hence skip this loop
            if(!ans.empty()) {
                if(start <= ans.back()[1]) continue;
            }

            for(int j = i + 1; j < rowsize; j++) {
                // since array is sorted & if overlapping happens start won't change
                // just compare the startTemp with end
                int startTemp = intervals[j][0];
                if(startTemp <= end) {
                    int endTemp = intervals[j][1]; 
                    end = max(end, endTemp);
                }
            }

            ans.push_back({start, end});
        }

        return ans;
    }
};

// tc -> O(nlogn) + O(n^2) = O(n^2)
// sc -> O(n)


// Optimal Approach:

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int rowsize = intervals.size();

        if(rowsize <= 1) return intervals;

        // step 1: ensure the array is sorted
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> ans;

        // step 2: insert first row in ans
        ans.push_back(intervals[0]);

        // step 3: traverse the whole array once
        for(int i = 1; i < rowsize; i++) {
            int startTemp = intervals[i][0];
            int endTemp = intervals[i][1];

            // overlapping
            // startTemp <= prevEnd
            if(startTemp <= ans.back()[1]) {
                // update the end
                ans.back()[1] = max(ans.back()[1], endTemp);
            } else {
                // no overlapping
                // insert the new interval
                ans.push_back(intervals[i]);
            }
        }
        return ans;
    }
};

// tc -> O(nlogn) + O(n) = O(nlogn)
// sc -> O(n)