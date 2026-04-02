#include <iostream>
#include <vector>

using namespace std;

int search(vector<int>& nums, int target) {
    int left = 0,
        right = nums.size() - 1;

    while(left <= right){

        int mid = left + (right - left)/2;
        if(nums[mid] == target) return mid;
        if(nums[mid] < target) left = mid +1;
        else right = mid - 1;
    }


    return -1;
}

int main() {
    vector<int> nums = {1, 3, 5, 7, 9};
    int target = 7;

    int result = search(nums, target);
    cout << result << endl;

    return 0;
}
