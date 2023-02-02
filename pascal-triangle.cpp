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


// Optimised Sol 2:
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
// tc -> O(n^2)
// sc -> O(1)