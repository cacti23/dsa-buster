// Brute Force:
// Time complexity will be N*N! because for any given array of length N there are N! possible permutations, and we need to print all of them so time complexity is O(n * n!).

// Space complexity will can be O(n) (backtracking) or O(n!). Depends on solutions implementation

// Optimised Sol:
class Solution {
public:
    void reverse(vector<int> &arr, int start, int end) {
        for(int i = start, j = end; i < j; i++, j--) {
            swap(arr[i], arr[j]);
        }
    }
    void nextPermutation(vector<int>& nums) {
        int n = nums.size(), i = -1, j;

        if(n == 1) return;

        // step 1: find for the pivot element
        // a pivot is the first element from
        // end of sequence which doesn't follow
        // property of non-increasing suffix
        for(i = n - 2; i >= 0; i--) {
            if(nums[i] < nums[i + 1]) {
                break;
            }
        }

        // check if the pivot is not found
        if(i < 0) {
            reverse(nums, 0, n - 1);
            return;
        }

        // step 2: if the pivot is found find the successor in the suffix from end
        for(j = n - 1; j > i; j--) {
            if(nums[j] > nums[i]) {
                break;
            }
        }

        // swap the pivot and the successor 
        swap(nums[i], nums[j]);

        // step 3: reverse the elements from i + 1 to last to minimize
        reverse(nums, i + 1, n - 1);
    }
};

// tc -> O(n)
// sc -> O(1)