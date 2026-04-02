#include <iostream>
#include <vector>
using namespace std;

// 1. Exact match
int binarySearch(vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (nums[mid] == target) return mid;
        else if (nums[mid] < target) left = mid + 1;
        else right = mid - 1;
    }

    return -1;
}

// 2. Lower Bound (first >= target)
int lowerBound(vector<int>& nums, int target) {
    int left = 0, right = nums.size();

    while (left < right) {
        int mid = left + (right - left) / 2;

        if (nums[mid] < target)
            left = mid + 1;
        else
            right = mid;
    }

    return left;
}

// 3. Upper Bound (first > target)
int upperBound(vector<int>& nums, int target) {
    int left = 0, right = nums.size();

    while (left < right) {
        int mid = left + (right - left) / 2;

        if (nums[mid] <= target)
            left = mid + 1;
        else
            right = mid;
    }

    return left;
}

// 4. Last <= target
int lastLessOrEqual(vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1;
    int ans = -1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (nums[mid] <= target) {
            ans = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return ans;
}

int main() {
    vector<int> nums = {1, 2, 4, 4, 5, 7, 9};
    int target = 4;

    cout << "Binary Search (exact): " << binarySearch(nums, target) << endl;
    cout << "Lower Bound (>=): " << lowerBound(nums, target) << endl;
    cout << "Upper Bound (>): " << upperBound(nums, target) << endl;
    cout << "Last <= target: " << lastLessOrEqual(nums, target) << endl;

    return 0;
}
