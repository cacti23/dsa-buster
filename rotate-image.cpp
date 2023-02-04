// Brute Force:
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> rotated(n, vector<int>(n,0));

        // copy values to rotated (answer) array
        for(int row = 0; row < n; row++) {
            for(int col = 0; col < n; col++) {
                rotated[col][n - 1 - row] = matrix[row][col];
            }
        } 

        // since pass by reference is used hence we need to copy
        // the rotated to maxtrix
        for(int row = 0; row < n; row++) {
            for(int col = 0; col < n; col++) {
                matrix[row][col] = rotated[row][col];
            }
        } 

    }
};

// tc -> O(n^2)
// sc -> O(n^2)

// Optimised Sol:
class Solution {
public:
    void reverse(vector<int> & arr, int n) {
        int i = 0, j = n - 1;

        while(i < j) {
            swap(arr[i++], arr[j--]);
        }
    }

    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();

        // step 1: transpose the matrix 
        // convert cols into rows   
        for(int row = 0; row < n; row++) {
            for(int col = 0; col < row; col++) {
                swap(matrix[row][col], matrix[col][row]);
            }
        }

        // step 2: reverse each col
        for(int row = 0; row < n; row++) {
                reverse(matrix[row], n);
        }
    }
};

// tc -> O(n^2)
// sc -> O(1)