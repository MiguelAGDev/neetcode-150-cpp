/*
Longest Repeating Character Replacement - Medium

You are given a string s consisting of only uppercase english characters and an integer k. You can choose up to k characters of the string and replace them with any other uppercase English character.
After performing at most k replacements, return the length of the longest substring which contains only one distinct character.

Example 1:
Input: s = "XYYX", k = 2
Output: 4
Explanation: Either replace the 'X's with 'Y's, or replace the 'Y's with 'X's.

Example 2:
Input: s = "AAABABB", k = 1
Output: 5

Constraints:
1 <= s.length <= 1000
0 <= k <= s.length

*/

#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int characterReplacement(string s, int k) {

    unordered_map <char, int> freq;
    int left = 0, max_size = 0 , max_freq = 0;


    for(int right = 0; right < s.size(); right++){

        char c = s[right];

        freq[c]++;

        max_freq = max(max_freq, freq[c]);

        int changes = (right - left + 1) - max_freq;
        while(changes > k) {


            freq[s[left]]--;
            left++;

            changes = (right - left + 1) - max_freq;
        }


        max_size = max(max_size, (right - left + 1));

    }

    return max_size;
}

int main()
{
    string s;
    cout << "Insert STRING: ";
    getline(cin,s);
    cout<< endl;

    int k;
    cout << "Insert K exceptions: ";
    cin>>k;
    cout<< endl;

    cout<<"Longest Substring: "<<characterReplacement(s,k)<<endl;



    return 0;
}
