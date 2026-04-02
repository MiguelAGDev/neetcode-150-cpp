
/*
Search a 2D Matrix - Medium

You are given an m x n 2-D integer array matrix and an integer target.

Each row in matrix is sorted in non-decreasing order.
The first integer of every row is greater than the last integer of the previous row.
Return true if target exists within matrix or false otherwise.

Can you write a solution that runs in O(log(m * n)) time?

Example 1:
Input: matrix = [[1,2,4,8],[10,11,12,13],[14,20,30,40]], target = 10
Output: true

Example 2:
Input: matrix = [[1,2,4,8],[10,11,12,13],[14,20,30,40]], target = 15
Output: false

Constraints:
m == matrix.length
n == matrix[i].length
1 <= m, n <= 100
-10000 <= matrix[i][j], target <= 10000
*/

#include <iostream>
#include <vector>
using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target) {

    int left = 0;
    int right = (matrix[0].size() * matrix.size()) - 1;

    while(left <= right){

        // matrix=[[1,3,5,7],[10,11,16,20],[23,30,34,60]]
        // target=3

        // left = 0
        // right = 11x 4 1

        // mid = 5x 2x 0
        int mid = left + (right - left)/2;

        // row = 1x 0x 0
        // col = 1x 2x 0
        int row =  mid  / matrix[0].size() ;
        int col = mid % matrix[0].size();

        // matrix [1][1] (11) == 3 x
        // matrix [0][2] (5) == 3 x
        // matrix [0][0] (1) == 3 x
        if(matrix[row][col] == target) return true;

        // matrix [1][2] (11) < 3 x
        // matrix [0][2] (5) < 3 x
        // matrix [0][0] (1) < 3 1
        if(matrix[row][col] < target) left = mid + 1;

        // matrix [1][2] (11) >= 3
        // matrix [0][2] (5) >= 3
        else right = mid - 1;

    }

    return false;

}

int main() {
    vector<vector<int>> matrix = {
        {1, 3, 5, 7},
        {10, 11, 16, 20},
        {23, 30, 34, 60}
    };

    int target = 3;

    cout << searchMatrix(matrix, target) << endl;

    return 0;
}
