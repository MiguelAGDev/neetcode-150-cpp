#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {

    unordered_map <int, vector<int> > unmap;

    int i = -1;
    for(int n : nums)
        unmap[n].push_back(++i);


    for(int n1 : nums){
        int n2 = target - n1;

        if(unmap.count(n2)){

            if(n1 != n2)
                return {unmap[n1][0], unmap[n2][0]};
            else if(unmap[n1].size() > 1)
                return {unmap[n1][0], unmap[n2][1]};
        }
    }

    return{};
}


int main()
{
    vector<int> nums = {1, 3, 4, 2};
    int target = 6;

    vector<int> result = twoSum(nums, target);

    if (!result.empty()) {
        cout << result[0] << " " << result[1] << endl;
    } else {
        cout << "No solution" << endl;
    }

    return 0;
}

