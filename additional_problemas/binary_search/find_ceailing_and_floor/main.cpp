#include <iostream>
#include <vector>
using namespace std;

int floor(vector<int> &nums, int &target){

    int left = 0, right = nums.size() - 1;
    int ans = -1;

    while(left <= right){


        int mid = left + (right - left)/2;

        if(nums[mid] <= target){
            ans = mid;
            left = mid + 1;
        }else{
            right = mid - 1;
        }

    }

    return (ans != -1)? nums[ans]: ans;

}

int ceiling(vector<int> &nums, int &target){

    int left = 0, right = nums.size() - 1;
    int ans = -1;

    while(left <= right){

        int mid = left + (right - left)/2;

        if(nums[mid] < target)
            left = mid + 1;
        else{
            ans = mid;
            right = mid - 1;
        }


    }

    return (ans != -1) ? nums[ans] : ans;

}

int main() {
    vector<int> nums = {1, 3, 5,7,9 };
    int target1 = 6;
    int target2 = 8;

    cout << "Array: ";
    for(int x : nums) cout << x << " ";
    cout << endl;

    cout << "Floor de " << target1 << ": " << floor(nums, target1) << endl;
    cout << "Ceiling de " << target1 << ": " << ceiling(nums, target1) << endl;

    cout << "Floor de " << target2 << ": " << floor(nums, target2) << endl;
    cout << "Ceiling de " << target2 << ": " << ceiling(nums, target2) << endl;

    return 0;
}


