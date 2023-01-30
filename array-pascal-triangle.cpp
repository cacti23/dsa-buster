// Info
// Use this formula when value of row and col is given -> (n-1)C(k-1) where n is the row number and k is the col number.

// Calculate value of
    // [n * (n-1) *---* (n-k+1)] / [k * (k-1) *----* 1]
    // res = 1;
    // for (int i = 0; i < k; ++i) {
    //     res *= (n - i);
    //     res /= (i + 1);
    // }

// Optimised Sol 1:
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans(numRows);

        // iterate through all rows
        for(int row = 0; row < numRows; row++) {
            // row val equals to value of elements in that row
            ans[row].resize(row + 1); // row starts from 0
            // first and last value of every row will be 1
            ans[row][0] = ans[row][row] = 1;

            // col will start from 1st and end on 2nd last element
            for(int col = 1; col < row; col++) {
                ans[row][col] = ans[row - 1][col - 1] + ans[row - 1][col];
            }
        }

        return ans;        
    }
};

// tc -> O(n^2)
// sc -> O(n^2)
// Time complexity will be O(n²) because the outer loop iterates n times, and for each iteration of the outer loop, the inner loop iterates i times, where i ranges from 0 to n-1. The total number of iterations is the sum of i from 0 to n-1 which is n(n+1)/2. So the time complexity is O(n²).

// Space complexity will be O(n2) precisely it will be O(n²/2) because for we for each the the number of element is equal to the row number. Also here in this solution we will need that additional array to calculate the values.


// Optimised Sol 2:
// consider this

// if we can relate the current element with previous element then we can calculate the current value in O(1).

// where line means row and i means column

// C(line, i)   = line! / ( (line-i)! * i! )
// C(line, i-1) = line! / ( (line - i + 1)! * (i-1)! )

// divide the above two expressions: 

// We can derive following expression from above two expressions.
// C(line, i) = C(line, i-1) * (line - i + 1) / i
// Using this formula we know that every row starts with , now check the code below:

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans(numRows);

        // iterate through all rows
        for(int row = 1; row <= numRows; row++) {
            // every row start with 1
            ans[row - 1].resize(row);
            int c = 1;
            for(int col = 1; col <= row; col++) {
                ans[row - 1][col - 1] = c;
                c = c * (row - col) / col;
            }
        }

        return ans;        
    }
};

// tc -> O(n^2)
// sc -> O(1)
// Time complexity will be same as above but space complexity is reduced to O(1) ignore the ans (required in question) arrays we don’t need it to calculate the values as above.