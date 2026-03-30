/*

Best Time to Buy and Sell Stock -Easy

You are given an integer array prices where prices[i] is the price of NeetCoin on the ith day.
You may choose a single day to buy one NeetCoin and choose a different day in the future to sell it.

Return the maximum profit you can achieve. You may choose to not make any transactions, in which case the profit would be 0.

Example 1:
Input: prices = [10,1,5,6,7,1]
Output: 6
Explanation: Buy prices[1] and sell prices[4], profit = 7 - 1 = 6.

Example 2:
Input: prices = [10,8,7,5,2]
Output: 0
Explanation: No profitable transactions can be made, thus the max profit is 0.

Constraints:

1 <= prices.length <= 100
0 <= prices[i] <= 100

*/

#include <iostream>
#include <stack>
#include <vector>
using namespace std;


    int maxProfit(vector<int>& prices) {

        stack <int> st;
        int min_ = INT_MAX;
        int max_profit = 0;

        for(int price: prices){
            min_ = min(min_,price);
            max_profit = max(max_profit, price - min_);

        }

        return max_profit;

    }



int main()
{
    vector<int> prices = {10,1,5,6,7,1};

    cout<<"prices = { ";
    for(int price: prices) cout<<price<<" ";
    cout<<"}"<<endl;

    cout<<"Maximun Profit: "<<maxProfit(prices)<<endl;
    return 0;
}
