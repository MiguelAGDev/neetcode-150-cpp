#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> sol;
        int product = 1, countZero = 0;

        // calcular producto y contar ceros
        for(int n: nums){
            if(n) product *= n;
            else countZero++;
        }

        // llenar vector resultado
        for(int n: nums){
            if(countZero > 1 || (countZero && n)){
                sol.push_back(0);
            } else if(n && !countZero){
                sol.push_back(product / n);
            } else if(!n && countZero){
                sol.push_back(product);
            }
        }

        return sol;
    }
};

int main() {
    Solution sol;

    // ejemplo de prueba
    vector<int> nums = {1, 2, 3, 4};
    vector<int> result = sol.productExceptSelf(nums);

    cout << "Input: ";
    for(int n : nums) cout << n << " ";
    cout << "\nOutput: ";
    for(int n : result) cout << n << " ";
    cout << endl;

    // prueba con ceros
    vector<int> nums2 = {1, 0, 3, 0};
    vector<int> result2 = sol.productExceptSelf(nums2);

    cout << "Input: ";
    for(int n : nums2) cout << n << " ";
    cout << "\nOutput: ";
    for(int n : result2) cout << n << " ";
    cout << endl;

    return 0;
}
