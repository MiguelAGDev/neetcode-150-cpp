/*

Container With Most Water
Solved
Medium
Topics
Company Tags
Hints
You are given an integer array heights where heights[i] represents the height of the
i
t
h
i
th
  bar.

You may choose any two bars to form a container. Return the maximum amount of water a container can store.

Example 1:



Input: height = [1,7,2,5,4,7,3,6]

Output: 36
Example 2:

Input: height = [2,2,2]

Output: 4
Constraints:

2 <= height.length <= 1000
0 <= height[i] <= 1000

// FOTO DE REFERENCIA
https://imagedelivery.net/CLfkmk9Wzy8_9HRyug4EVA/77f004c6-e773-4e63-7b99-a2309303c700/public

*/


#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& heights) {

        int max_area = 0, current_area, left = 0, right = heights.size() -1;
        while(left < right){

            current_area = (heights[left] < heights[right])
            ? (right - left) * heights[left]
            : (right - left) * heights[right];

            if(current_area > max_area)
                max_area = current_area;

            if(heights[left] < heights[right]) left++;
            else if(heights[left] > heights[right]) right--;
            else {left++; right--;}
        }

        return max_area;
    }
};

int main() {
    Solution sol;

    vector<int> heights = {1,8,6,2,5,4,8,3,7};

    int result = sol.maxArea(heights);

    cout << "Max area: " << result << endl;

    return 0;
}
