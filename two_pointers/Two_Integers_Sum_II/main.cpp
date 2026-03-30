/*
Two Integer Sum II
Solved
Medium
Topics
Company Tags
Hints
Given an array of integers numbers that is sorted in non-decreasing order.

Return the indices (1-indexed) of two numbers, [index1, index2], such that they add up to a given target number target and index1 < index2. Note that index1 and index2 cannot be equal, therefore you may not use the same element twice.

There will always be exactly one valid solution.

Your solution must use
O
(
1
)
O(1) additional space.

Example 1:

Input: numbers = [1,2,3,4], target = 3

Output: [1,2]
Explanation:
The sum of 1 and 2 is 3. Since we are assuming a 1-indexed array, index1 = 1, index2 = 2. We return [1, 2].

Constraints:

2 <= numbers.length <= 1000
-1000 <= numbers[i] <= 1000
-1000 <= target <= 1000


*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {

        int l = 0, r = numbers.size() - 1, current_target;

        while(l < r){
            current_target = numbers[l] + numbers[r];

            if(current_target == target)
                return {++l, ++r};
            if(current_target < target)
                l++;
            else // current_target > target
                r--;
        }

        return {0,0};
    }
};

int main() {
    Solution sol;

    vector<int> numbers1 = {1, 2, 3, 4};
    int target1 = 3;

    vector<int> result = sol.twoSum(numbers1, target1);

    cout << "[" << result[0] << "," << result[1] << "]" << endl;

    // Más tests extremos
    vector<int> numbers2 = {-1000, -500, 0, 500, 1000};
    int target2 = 0;
    result = sol.twoSum(numbers2, target2);
    cout << "[" << result[0] << "," << result[1] << "]" << endl;

    vector<int> numbers3 = {1, 3, 5, 7, 9, 11, 13, 15};
    int target3 = 16;
    result = sol.twoSum(numbers3, target3);
    cout << "[" << result[0] << "," << result[1] << "]" << endl;

    return 0;
}

