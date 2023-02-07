// Brute Force:
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();

        // step 1: sort the array
        sort(nums.begin(), nums.end());

        // step 2: find the duplicate
        for(int i = 0; i < n - 1; i++) {
            if(nums[i] == nums[i + 1]) return nums[i];
        }

        return -1;
    }
};

// tc -> O(nlogn) + O(n) = O(nlogn)
// sc -> O(1)

// Optimal Sol 1:
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // step 1: create frequncy array
        int n = nums.size();
        vector<int> freq(n - 1);

        // step 2: populate the freq array
        for(int i = 0; i < n; i++) {
            freq[nums[i] - 1]++;
        }

        // step 3: get the ans
        for(int i = 0; i < n - 1; i++) {
            if(freq[i] > 1) {
                return  i + 1;
            }
        }

        return -1;
    }
};

// tc -> O(n)
// sc -> O(n)

// Optimal Sol 2:
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // step 1: fast and slow pointers
        int slow = nums[0];
        int fast = nums[0];

        // step 2: traverse the cycle
        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while(slow != fast);

        // after above loop collision happened
        // set fast to starting position
        fast = nums[0];
        
        // step 3: get the ans
        while(slow != fast) {
            // slow moves one time 
            slow = nums[slow];
            // fast moves one time
            fast = nums[fast];
        }

        return slow;
    }
};

// tc -> O(n)
// sc -> O(1)