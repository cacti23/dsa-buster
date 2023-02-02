// Sol 1: (Sorting)
// Time Complexity: O(N*logN)
// Space Complexity: O(n)

// Optimised Sol 2: (Keeping The Count)
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();

        if(n == 1) return;

        // a, b and c keeps the count of 0, 1 and 2
        int a = 0, b = 0, c = 0;

        // traver array once to gather the count of 0, 1 and 2
        for(int i = 0; i < n; i++) {
            if(nums[i] == 0) a++;
            else if(nums[i] == 1) b++;
            else c++;
        }

        // using count insert the value of 0, 1 and 2 in the given array
        for(int i = 0; i < n; i++) {
            if(a > 0) {
                nums[i] = 0;
                a--;
            } else if(b > 0) {
                nums[i] = 1;
                b--;
            } else if(c > 0) {
                nums[i] = 2;
                c--;
            }
        }
    }
};

// tc -> O(n)
// sc -> O(1)

// Optimised Sol 3: (Dutch National Flag Problem)
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();

        if(n == 1) return;

        // a, b and c keeps the count of 0, 1 and 2
        int a = 0, b = 0, c = 0;

        // traver array once to gather the count of 0, 1 and 2
        for(int i = 0; i < n; i++) {
            if(nums[i] == 0) a++;
            else if(nums[i] == 1) b++;
            else c++;
        }

        // using count insert the value of 0, 1 and 2 in the given array
        for(int i = 0; i < n; i++) {
            if(a > 0) {
                nums[i] = 0;
                a--;
            } else if(b > 0) {
                nums[i] = 1;
                b--;
            } else if(c > 0) {
                nums[i] = 2;
                c--;
            }
        }
    }
};

// tc -> O(n)
// sc -> O(1)