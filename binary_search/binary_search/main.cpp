/*
Binary Search - Easy

You are given an array of distinct integers nums, sorted in ascending order, and an integer target.
Implement a function to search for target within nums. If it exists, then return its index, otherwise, return -1.

Your solution must run in  O(logn) time.

Example 1:
Input: nums = [-1,0,2,4,6,8], target = 4
Output: 3

Example 2:
Input: nums = [-1,0,2,4,6,8], target = 3

Output: -1
Constraints:

1 <= nums.length <= 10000.
-10000 < nums[i], target < 10000
All the integers in nums are unique.


*/


#include <iostream>
#include <vector>

using namespace std;

int search(vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1;

    while(left <= right){
        int mid = left + (right - left)/2;
        if(nums[mid] == target) return mid;
        if(nums[mid] < target) left = mid +1;
        else right = mid - 1;
    }
    return -1;
}


int main() {
    vector<int> nums = {1, 3, 5, 7, 9, 11, 13};
    int target = 7;

    int result = search(nums, target);

    if(result != -1)
        cout << "Target found at index: " << result << endl;
    else
        cout << "Target not found." << endl;

    return 0;
}
