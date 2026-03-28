/*


Top K Frequent Elements - Medium

Given an integer array nums and an integer k, return the k most frequent elements within the array.
The test cases are generated such that the answer is always unique.

You may return the output in any order.


Example 1:
Input: nums = [1,2,2,3,3,3], k = 2
Output: [2,3]

Example 2:
Input: nums = [7,7], k = 1
Output: [7]

Constraints:
1 <= nums.length <= 10^4.
-1000 <= nums[i] <= 1000
1 <= k <= number of distinct elements in nums.

*/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> topKFrequent(vector<int>& nums, int k) {

    unordered_map<int, int> freq;

    for(int n: nums)
        freq[n]++;

    vector<vector<int>> bucket(nums.size() + 1);

    for(auto p: freq){
        int num = p.first;
        int f = p.second;

        bucket[f].push_back(num);
    }

    vector<int> sol;
    for(int f = bucket.size() - 1; f > -1; f--){
        for(int n: bucket[f]){
            sol.push_back(n);

            if(sol.size() == k)
                break;

        }

        if(sol.size() == k)
            break;
    }

    return sol;
}

int main() {

    vector<int> nums = {1,1,1,2,2,3};
    int k = 2;

    vector<int> result = topKFrequent(nums, k);

    cout << "Result: ";
    for(int n: result)
        cout << n << " ";
    cout << endl;

    return 0;
}
