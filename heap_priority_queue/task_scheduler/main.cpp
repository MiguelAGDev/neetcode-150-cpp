/*
Task Scheduler - Medium

You are given an array of CPU tasks tasks, where tasks[i] is an uppercase english character from A to Z. You are also given an integer n.
Each CPU cycle allows the completion of a single task, and tasks may be completed in any order.
The only constraint is that identical tasks must be separated by at least n CPU cycles, to cooldown the CPU.
Return the minimum number of CPU cycles required to complete all tasks.

Example 1:
Input: tasks = ["X","X","Y","Y"], n = 2
Output: 5
Explanation: A possible sequence is: X -> Y -> idle -> X -> Y.

Example 2:
Input: tasks = ["A","A","A","B","C"], n = 3
Output: 9
Explanation: A possible sequence is: A -> B -> C -> Idle -> A -> Idle -> Idle -> Idle -> A.

Constraints:
1 <= tasks.length <= 10000
0 <= n <= 100

*/
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {

        unordered_map<char, int> freq;

        for (char task : tasks) {
            freq[task]++;
        }

        priority_queue<int> maxHeap;

        for (auto [task, count] : freq) {
            maxHeap.push(count);
        }

        queue<pair<int, int>> cooldown;

        int time = 0;

        while (!maxHeap.empty() || !cooldown.empty()) {

            time++;

            if (!maxHeap.empty()) {

                int count = maxHeap.top();
                maxHeap.pop();

                count--;

                if (count > 0) {
                    cooldown.push({count, time + n});
                }
            }

            if (!cooldown.empty() && cooldown.front().second == time) {
                maxHeap.push(cooldown.front().first);
                cooldown.pop();
            }
        }

        return time;
    }
};

int main() {

    vector<char> tasks = {'X', 'X', 'Y', 'Y'};
    int n = 2;

    Solution sol;
    cout << sol.leastInterval(tasks, n) << endl; // 5

    return 0;
}
