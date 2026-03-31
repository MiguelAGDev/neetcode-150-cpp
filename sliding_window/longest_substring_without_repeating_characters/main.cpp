/*

Longest Substring Without Repeating Characters - Medium

Given a string s, find the length of the longest substring without duplicate characters.
A substring is a contiguous sequence of characters within a string.

Example 1:
Input: s = "zxyzxyz"
Output: 3
Explanation: The string "xyz" is the longest without duplicate characters.

Example 2:
Input: s = "xxxx"
Output: 1

Constraints:
0 <= s.length <= 1000
s may consist of printable ASCII characters.

*/

#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;


int lengthOfLongestSubstring(string s) {

    unordered_set <char> seen;

    int left = 0;
    int max_size = 0;

    for(int right = 0; right < s.size(); right++){

        char cur = s[right];

        if(seen.count(cur)){
            while(s[left] != cur){
                seen.erase(s[left]);
                left++;
            }
            left++;
        }

        seen.insert(cur);
        max_size = max(max_size, right - left + 1);
    }

    return max_size;

}

int main()
{
    string s;
    cin>>s;
    cout<<"Maximun Substring: " <<lengthOfLongestSubstring(s)<<endl;
    return 0;
}
