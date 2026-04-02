/*
Largest Rectangle In Histogram - Hard

You are given an array of integers heights where heights[i] represents the height of a bar. The width of each bar is 1.
Return the area of the largest rectangle that can be formed among the bars.

Note: This chart is known as a histogram.

Example 1:
Input: heights = [7,1,7,2,2,4]
Output: 8

Example 2:
Input: heights = [1,3,7]
Output: 7

Constraints:
1 <= heights.length <= 1000.
0 <= heights[i] <= 1000

*/


#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int largestRectangleArea(vector<int>& heights) {

    if (heights.empty()) return 0;

    stack< pair <int, int>> st;

    int max_area = -1;

    for(int i = 0; i < heights.size(); i++){

        int start = i;
        int cur_height = heights[i];

        // MIENTRAS LA PILA NO ESTE VACIA
        // Y EL INDEX DLE TOPE SEA MAYOR A LA ALTURA ACTUAL
        while(!st.empty() && st.top().first > cur_height){

            int height = st.top().first;
            int index = st.top().second;

            st.pop();


            max_area = max(max_area, (i - index) * height);
            start = index;
        }

        st.push({cur_height, start});

    }

    while(!st.empty()){


        int height = st.top().first;
        int index = st.top().second;

        st.pop();

        max_area = max(max_area, (int)(heights.size() - index) * height);
    }


    return max_area;


}

int main() {


    vector<int> heights = {2, 1, 5, 6, 2, 3};

    int result = largestRectangleArea(heights);

    cout << "Largest Rectangle Area: " << result << endl;

    return 0;
}
