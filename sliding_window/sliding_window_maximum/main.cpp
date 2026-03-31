/*
Sliding Window Maximum - Hard

You are given an array of integers nums and an integer k. There is a sliding window of size k that starts at the left edge of the array. The window slides one position to the right until it reaches the right edge of the array.
Return a list that contains the maximum element in the window at each step.

Example 1:
Input: nums = [1,2,1,0,4,2,6], k = 3
Output: [2,2,4,4,6]

Explanation:
Window position            Max
---------------           -----
[1  2  1] 0  4  2  6        2
 1 [2  1  0] 4  2  6        2
 1  2 [1  0  4] 2  6        4
 1  2  1 [0  4  2] 6        4
 1  2  1  0 [4  2  6]       6

Constraints:
1 <= nums.length <= 100,000
-10,000 <= nums[i] <= 10,000
1 <= k <= nums.length

*/

#include <iostream>
#include <vector>
#include <set>
using namespace std;


vector<int> maxSlidingWindow(vector<int>& nums, int k) {

    if(k==1) return nums;

    int left = 0, right;
    vector<int> cur_max, cur_aux;

    multiset<int> cur_array;
    int max = 0;

    int c = k;

    for(int i: nums){
        if(!c) break;
        cur_array.insert(i);
        c--;
    }

    for(right = k - 1; right < nums.size();){
        auto prelast = prev(cur_array.end(), 2);
        auto last = prev(cur_array.end(), 1);


        if(*last < *prelast){
            cur_max.push_back(*prelast);
            cur_array.erase(cur_array.find(nums[left]));
        }else{
            cur_max.push_back(*last);
            cur_array.erase(cur_array.find(nums[left]));
        }


        left++;
        right++;
        cur_array.insert(nums[right]);
    }

    return cur_max;
}



int main()
{
    vector<int> nums = {1,3,-1,-3,5,3,6,7};
    int k = 3;

    cout << "nums = { ";
    for(int n : nums) cout << n << " ";
    cout << "}" << endl;

    cout << "k = " << k << endl;

    vector<int> result = maxSlidingWindow(nums, k);

    cout << "Output: { ";
    for(int n : result) cout << n << " ";
    cout << "}" << endl;

    return 0;
}
