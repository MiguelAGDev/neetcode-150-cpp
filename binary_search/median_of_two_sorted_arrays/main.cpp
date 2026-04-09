/*
Median of Two Sorted Arrays - Hard

You are given two integer arrays nums1 and nums2 of size m and n respectively, where each is sorted in ascending order. Return the median value among all elements of the two arrays.

Your solution must run in O(log(m+n)) time.

Example 1:
Input: nums1 = [1,2], nums2 = [3]
Output: 2.0
Explanation: Among [1, 2, 3] the median is 2.

Example 2:
Input: nums1 = [1,3], nums2 = [2,4]
Output: 2.5
Explanation: Among [1, 2, 3, 4] the median is (2 + 3) / 2 = 2.5.

Constraints:
    nums1.length == m
    nums2.length == n
    0 <= m <= 1000
    0 <= n <= 1000
    -10^6 <= nums1[i], nums2[i] <= 10^6

*/

#include <iostream>
#include <vector>
using namespace std;

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    // Siempre ejecutamos para saber cual es el array
    // con el menor size
    if(nums1.size() > nums2.size())
        return findMedianSortedArrays(nums2, nums1);

    int m = nums1.size();
    int n = nums2.size();

    // left = 0 y right = size menor;
    int left = 0, right = m;

    while(left <= right){

        int i = left + (right - left) / 2;
        int j = (m + n + 1) / 2 - i;

        int left1 = (i == 0) ? INT_MIN : nums1[i - 1];
        int right1 = (i == m) ? INT_MAX : nums1[i];

        int left2 = (j == 0) ? INT_MIN : nums2[j - 1];
        int right2 = (j == n) ? INT_MAX : nums2[j];

        if(left1 <= right2 && left2 <= right1){

            if( (m + n) % 2){
                return max(left1, left2);
            }else{
                return (max(left1,left2) + min(right1, right2)) / 2.0;
            }

        }else if (left1 > right2){
            right = i - 1;
        }else {
            left = i + 1;
        }

    }


    return 0.0;
}


int main() {

    vector<int> nums1 = {1, 4, 7, 10, 12, 15};
    vector<int> nums2 = {2, 3, 5, 6, 8, 9, 11, 13, 14};

    double result = findMedianSortedArrays(nums1, nums2);
    cout << "Median 1: " << result << endl;

    nums1 = {1, 2, 3, 4, 5, 6, 7, 8};
    nums2 = {9, 10, 11, 12, 13, 14, 15, 16};

    result = findMedianSortedArrays(nums1, nums2);
    cout << "Median 2: " << result << endl;

    nums1 = {1, 3, 8, 9, 15, 20, 25};
    nums2 = {7, 11, 18, 19, 21, 22, 23, 24};

    result = findMedianSortedArrays(nums1, nums2);
    cout << "Median 3: " << result << endl;

    nums1 = {5, 6, 7, 8, 9};
    nums2 = {1, 2, 3, 4, 10, 11, 12, 13, 14, 15};

    result = findMedianSortedArrays(nums1, nums2);
    cout << "Median 4: " << result << endl;

    return 0;
}

