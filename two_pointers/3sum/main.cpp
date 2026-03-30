/*

3Sum
Solved
Medium
Topics
Company Tags
Hints
Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] where nums[i] + nums[j] + nums[k] == 0, and the indices i, j and k are all distinct.

The output should not contain any duplicate triplets. You may return the output and the triplets in any order.

Example 1:

Input: nums = [-1,0,1,2,-1,-4]

Output: [[-1,-1,2],[-1,0,1]]
Explanation:
nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
The distinct triplets are [-1,0,1] and [-1,-1,2].

Example 2:

Input: nums = [0,1,1]

Output: []
Explanation: The only possible triplet does not sum up to 0.

Example 3:

Input: nums = [0,0,0]

Output: [[0,0,0]]
Explanation: The only possible triplet sums up to 0.

Constraints:

3 <= nums.length <= 1000
-10^5 <= nums[i] <= 10^5

*/


#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        sort(nums.begin(), nums.end());

        vector<vector<int>> solution;

        int left = 1, right = nums.size() - 1;
        for(int pivot = 0; pivot < nums.size() - 2; pivot++){
            if(pivot > 0 && nums[pivot] == nums[pivot - 1]) continue;

            left = pivot + 1;
            right = nums.size() - 1;
            while(left < right){
                int current = nums[pivot] + nums[left] + nums[right];

                if(current == 0){
                    solution.push_back({nums[pivot] , nums[left] , nums[right]});

                    ++left; --right;
                    while(left < right && nums[left] == nums[left-1]) left++;
                    while(left < right && nums[right] == nums[right+1]) right--;

                }else if(current < 0){
                    ++left;
                }else if(current > 0){
                    --right;
                }


            } // END LEFT < RIGHT


        } // END FOR PIVOT

        return solution;

    }
};

int main() {
    Solution sol;
    vector<int> nums = {-1, 0, 1, 2, -1, -4};

    vector<vector<int>> result = sol.threeSum(nums);

    cout << "Tripletas que suman 0:\n";
    for (auto &triplet : result) {
        cout << "[ ";
        for (int num : triplet) {
            cout << num << " ";
        }
        cout << "]\n";
    }

    return 0;
}
