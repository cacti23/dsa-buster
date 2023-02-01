// Brute Force:
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // maxi store the maximum subarray value
        int maxi = INT_MIN;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                int sum = 0;
                for (int k = i; k <= j; k++) {
                    sum += nums[k];
                }
                maxi = max(maxi, sum);
            }
        }

        return maxi;
    }
};

// tc -> O(n^3)
// sc -> O(1)

// Brute force optimised:
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // maxi store the maximum subarray value
        int maxi = INT_MIN;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            int sum = 0;
            for (int j = i; j < n; j++) {
                sum += nums[j];
                maxi = max(maxi, sum);
            }
        }

        return maxi;
    }
};

// tc -> O(n^2)
// sc -> O(1)


// Optimised Sol: (Kadane’s Algorithm)
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // sum keeps the track of sum so far
        int sum = 0;
        // maxi store the maximum subarray value
        int maxi = INT_MIN;
        int n = nums.size();

        for(int i = 0; i < n; i++) {
            // add elements one by one to the sum
            sum += nums[i];
            // if the maxi is less then sum update it
            maxi = max(maxi, sum);
            // intialize sum by 0 if it is negative because negative number won't help to achieve the maximum sum
            if(sum < 0) sum = 0;
        }

        return maxi;
    }
};

// tc -> O(n)
// sc -> O(1)