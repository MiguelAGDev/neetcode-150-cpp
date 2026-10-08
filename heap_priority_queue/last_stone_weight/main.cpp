/*
Last Stone Weight - Easy

You are given an array of integers stones where stones[i] represents the weight of the ith stone.
We want to run a simulation on the stones as follows:

At each step we choose the two heaviest stones, with weight x and y and smash them togethers
If x == y, both stones are destroyed
If x < y, the stone of weight x is destroyed, and the stone of weight y has new weight y - x.

Continue the simulation until there is no more than one stone remaining.
Return the weight of the last remaining stone or return 0 if none remain.

Example 1:
Input: stones = [2,3,6,2,4]
Output: 1
Explanation: We smash 6 and 4 and are left with a 2, so the array becomes [2,3,2,2]. We smash 3 and 2 and are left with a 1, so the array becomes [1,2,2]. We smash 2 and 2, so the array becomes [1].

Example 2:
Input: stones = [1,2]
Output: 1

Constraints:
1 <= stones.length <= 20
1 <= stones[i] <= 100

*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        if(stones.size() == 1) return stones.back();

        priority_queue<int> heap;

        for(int st: stones) heap.push(st);

        int res;

        while(heap.size() > 1){

            int x = heap.top(); heap.pop();
            int y = heap.top(); heap.pop();

            res = x - y;

            if( res > 0 ) heap.push(res);

        }

        return heap.empty()? 0  : heap.top();
    }
};

int main() {

    vector<int> stones = {2, 3, 6, 2, 4};

    Solution sol;
    cout << sol.lastStoneWeight(stones) << endl; // 1

    return 0;
}
