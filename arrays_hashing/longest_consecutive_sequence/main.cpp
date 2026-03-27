/*


Longest Consecutive Sequence - Medium

Given an array of integers nums, return the length of the longest consecutive sequence of elements that can be formed.

A consecutive sequence is a sequence of elements in which each element is exactly 1 greater than the previous element. The elements do not have to be consecutive in the original array.

You must write an algorithm that runs in O(n) time.

Example 1:
    Input: nums = [2,20,4,10,3,4,5]
    Output: 4
    Explanation: The longest consecutive sequence is [2, 3, 4, 5].

Example 2:
    Input: nums = [0,3,2,5,4,6,1,1]
    Output: 7

Constraints:

0 <= nums.length <= 1000
-10^9 <= nums[i] <= 10^9


*/

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int longestConsecutive(vector<int>& nums) {

    unordered_set <int> num_set;

    for(int n: nums)
        num_set.insert(n);

    int count_sec = 1, max_sec = 0;
    for(int n : nums){

        if(num_set.count(n - 1))
            continue;

        while(num_set.count(n + 1)){
            n++;
            count_sec++;
        }


        max_sec = max(max_sec, count_sec);

        count_sec = 1;
    }

    return max_sec;
}

int main() {

    vector<int> nums = {2,20,4,10,3,4,5};

    int result = longestConsecutive(nums);

    cout << "Result: " << result << endl;

    return 0;
}
