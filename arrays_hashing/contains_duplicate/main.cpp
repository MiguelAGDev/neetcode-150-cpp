#include <iostream>
#include <unordered_set>
#include <vector>


/**
 * Given an integer array nums, return true if any value appears more
 * than once in the array, otherwise return false.
 */

using namespace std;

bool hasDuplicate(const vector<int>& nums)
{
    unordered_set <int> seen;

    for (int n : nums)
    {
        if (seen.count(n))
        {
            return true;
        }else
            seen.insert(n);
    }

    return false;
}

int main()
{
    vector<int> nums = {1, 2, 3, 3};

    if (hasDuplicate(nums))
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }

    return 0;
}
