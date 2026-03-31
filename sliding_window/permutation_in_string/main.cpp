/*
Permutation in String - Medium

You are given two strings s1 and s2.
Return true if s2 contains a permutation of s1, or false otherwise. That means if a permutation of s1 exists as a substring of s2, then return true.
Both strings only contain lowercase letters.

Example 1:
Input: s1 = "abc", s2 = "lecabee"
Output: true
Explanation: The substring "cab" is a permutation of "abc" and is present in "lecabee".

Example 2:
Input: s1 = "abc", s2 = "lecaabee"
Output: false

Constraints:
1 <= s1.length, s2.length <= 1000
*/

#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;


bool checkInclusion(string s1, string s2) {
    if(s1.size() > s2.size()) return false;

    unordered_map <char, int> freq_s1;
    unordered_map <char, int> freq_s2;

    for(char c: s1) freq_s1[c]++;

    int left = 0;

    for(int right = 0; right < s2.size(); right++){
        char c = s2[right];

        if(!freq_s1.count(c)) continue;

        freq_s2[c]++;

        while(right - left + 1 > s1.size()){
            if(freq_s1.count(s2[left])) freq_s2[s2[left]]--;

            left++;
        }

        if(freq_s1 == freq_s2) return true;
    }

    return false;


}

int main()
{
    string s1, s2;
    cout << "Insert string 1: ";
    getline(cin,s1);
    cout<<endl;

    cout << "Insert string 2: ";
    getline(cin,s2);
    cout<<endl;

    cout << "Has permutation? "<<checkInclusion(s1,s2)<<endl;


    return 0;
}
