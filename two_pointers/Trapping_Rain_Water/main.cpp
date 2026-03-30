/*

Trapping Rain Water
Solved
Hard
Topics
Company Tags
Hints
You are given an array of non-negative integers height which represent an elevation map. Each value height[i] represents the height of a bar, which has a width of 1.

Return the maximum area of water that can be trapped between the bars.

Example 1:



Input: height = [0,2,0,3,1,0,1,3,2,1]

Output: 9
Constraints:

1 <= height.length <= 1000
0 <= height[i] <= 1000

reference img  = https://imagedelivery.net/CLfkmk9Wzy8_9HRyug4EVA/0c25cb81-1095-4382-fff2-6ef77c1fd100/public


*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {

        int count_water = 0, left = 0, right = left + 1;

        while(left < height.size() - 2 && left < height.size() - 1){

            if(height[left] == 0){ left++; right++; continue;}

            // SI LA SIGUIENTE POSICION ES MENOR
            if( height[left] > height[right]){

                if (right == height.size()) break;
                if (right == height.size() - 1 && height[right] < height[right - 1]) break;

                int wall = height[left];

                while(height[right] < wall ){

                    right++;
                    if(right == height.size()){
                        wall--;
                        right = left + 1;
                    }
                }

                count_water += (right - left - 1) * min(height[left] , height[right] );

                for(int i = left + 1; i < right; i++)
                    count_water -= height[i];

                left = right - 1;
            }

            left++;
            right++;
        }

        return count_water;
    }
};

int main() {
    Solution sol;

    vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};

    int result = sol.trap(height);

    cout << "Agua atrapada: " << result << endl;

    return 0;
}
