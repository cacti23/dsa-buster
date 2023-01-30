// Brute force approach:
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int rowsize = matrix.size();
        int colsize = matrix[0].size();

        for(int row = 0; row < rowsize; row++) {
            for(int col = 0; col < colsize; col++) {
                if(matrix[row][col] == 0) {
                    // set row first
                    for(int i = 0; i < colsize; i++) {
                        if(matrix[row][i] != 0) {
                            matrix[row][i] = INT_MIN;
                        }
                    }

                    // set col 
                    for(int i = 0; i < rowsize; i++) {
                        if(matrix[i][col] != 0) {
                            matrix[i][col] = INT_MIN;
                        }
                    }
                }
            }
        }

        for(int row = 0; row < rowsize; row++) {
            for(int col = 0; col < colsize; col++) {
                if(matrix[row][col] == INT_MIN) {
                    matrix[row][col] = 0;
                }
            }
        }
    }

    // only works for non negative integers
    // tc -> O(n*m*(n+m))
    // sc -> O(1)
};


// Optimised Sol 1:
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int rowsize = matrix.size();
        int colsize = matrix[0].size();

        vector<int> dummyrow(rowsize, -1);
        vector<int> dummycol(colsize, -1);

        for(int row = 0; row < rowsize; row++) {
            for(int col = 0; col < colsize; col++) {
                if(matrix[row][col] == 0) {
                    dummyrow[row] = 0;
                    dummycol[col] = 0; 
                }
            }
        }

        for(int row = 0; row < rowsize; row++) {
            for(int col = 0; col < colsize; col++) {
                if(dummyrow[row] == 0 || dummycol[col] == 0) {
                    matrix[row][col] = 0;
                }
            }
        }
    }

    // tc -> O(n*m + n*m) -> O(n*m)
    // sc -> O(max(n, m))
};


// Optimised Sol 2:
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int rowsize = matrix.size();
        int colsize = matrix[0].size();
        // step 1: populate dummy row and dummy col
        // here we gonna treat 0th row as dummy row and 0th col as dummy col

        bool col0 = false; // represent the dummy col's 0th index

        for(int row = 0; row < rowsize; row++) {
            // if 0 is present in 0th col set col0 to true
            if(matrix[row][0] == 0) col0 = true;
            // start col form 1, since we have col0
            for(int col = 1; col < colsize; col++) {
                if(matrix[row][col] == 0) {
                    // set row, 0 as 0
                    matrix[row][0] = 0;
                    // set 0, col as 0
                    matrix[0][col] = 0;
                }
            }
        }

        // step 2: traverse the array from from the end and use dummy arrays to set zero
        for(int row = rowsize - 1; row >= 0; row--) {
            for(int col = colsize - 1; col >= 1; col--) {
                if(matrix[row][0] == 0 || matrix[0][col] == 0) {
                    matrix[row][col] = 0;
                }
            }

            // handle 0th col
            if(col0 == true) {
                matrix[row][0] = 0;
            }
        }
    }

    // tc -> O(n*m + n*m) -> O(n*m)
    // sc -> O(1)
};