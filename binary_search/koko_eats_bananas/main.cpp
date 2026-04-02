/*
Koko Eating Bananas - Medium

You are given an integer array piles where piles[i] is the number of bananas in the ith pile. You are also given an integer h, which represents the number of hours you have to eat all the bananas.
You may decide your bananas-per-hour eating rate of k. Each hour, you may choose a pile of bananas and eats k bananas from that pile. If the pile has less than k bananas, you may finish eating the pile but you can not eat from another pile in the same hour.

Return the minimum integer k such that you can eat all the bananas within h hours.

Example 1:
Input: piles = [1,4,3,2], h = 9
Output: 2
Explanation: With an eating rate of 2, you can eat the bananas in 6 hours. With an eating rate of 1, you would need 10 hours to eat all the bananas (which exceeds h=9), thus the minimum eating rate is 2.

Example 2:
Input: piles = [25,10,23,4], h = 4
Output: 25

Constraints:
1 <= piles.length <= 1,000
piles.length <= h <= 1,000,000
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

    int minEatingSpeed(vector<int>& piles, int h) {


        // ir ajusntando las horas.
        int left = 1;
        int right = *max_element(piles.begin(), piles.end());
        int k = 0;
        int mid;

        while(left < right){

            /// Hago un, busco la del medio
            /// [1,2,3,4]
            /// mid = 12
            // depues un
            // for que rego

            // left = 4
            // righ = 25

            // mid = (4 + 25)/ 2 = 14
            mid = left + (right - left)/2;
            k = 0;

            // k =
            for (int bananas: piles) k += ( bananas  + mid - 1 ) / mid;



            if(k > h) left = mid + 1;
            else right = mid ;

        }

        return left;

    }

int main() {
    vector<int> piles = {3, 6, 7, 11};
    int h = 8;

    cout << minEatingSpeed(piles, h) << endl;

    return 0;
}
