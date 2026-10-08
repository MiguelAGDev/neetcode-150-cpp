/*
K Closest Points to Origin - Medium

You are given an 2-D array points where points[i] = [xi, yi] represents the coordinates of a point on an X-Y axis plane. You are also given an integer k.
Return the k closest points to the origin (0, 0).
The distance between two points is defined as the Euclidean distance (sqrt((x1 - x2)^2 + (y1 - y2)^2)).
You may return the answer in any order. The answer is guaranteed to be unique(except for the order in which the points are returned.)

Example 1:
Input: points = [[0,2],[2,2]], k = 1
Output: [[0,2]]
Explanation : The distance between (0, 2) and the origin (0, 0) is 2. The distance between (2, 2) and the origin is sqrt(2^2 + 2^2) = 2.82842. So the closest point to the origin is (0, 2).

Example 2:
Input: points = [[0,2],[2,0],[2,2]], k = 2
Output: [[0,2],[2,0]]
Explanation: The output [2,0],[0,2] would also be accepted.

Constraints:
1 <= k <= points.length <= 1000
-100 <= points[i][0], points[i][1] <= 100

*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {

        priority_queue< pair < int, vector<int> > > pq;

        for(auto p : points ){

            int x = p[0];
            int y = p[1];

            int distance = ( x * x ) + ( y * y );
            pq.push( {distance, { x, y } } );

            if(pq.size() > k) pq.pop();

        }

        vector< vector <int> > sol;

        while( !pq.empty() ){
            sol.push_back( pq.top().second );
            pq.pop();
        }

        return sol;

    }
};

int main() {

    vector<vector<int>> points = {{0, 2}, {2, 2}};
    int k = 1;

    Solution sol;
    vector<vector<int>> res = sol.kClosest(points, k);

    // [[0,2]]
    cout << "[";
    for(int i = 0; i < res.size(); i++){
        cout << "[" << res[i][0] << "," << res[i][1] << "]";
        if(i + 1 < res.size()) cout << ",";
    }
    cout << "]" << endl;

    return 0;
}
