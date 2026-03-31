/*
Minimum Window Substring - Hard

Given two strings s and t, return the shortest substring of s such that every character in t, including duplicates, is present in the substring. If such a substring does not exist, return an empty string "".
You may assume that the correct output is always unique.

Example 1:
Input: s = "OUZODYXAZV", t = "XYZ"
Output: "YXAZ"
Explanation: "YXAZ" is the shortest substring that includes "X", "Y", and "Z" from string t.

Example 2:
Input: s = "xyz", t = "xyz"
Output: "xyz"

Example 3:
Input: s = "x", t = "xy"
Output: ""

Constraints:
1 <= s.length <= 1000
1 <= t.length <= 1000
s and t consist of uppercase and lowercase English letters.

*/

#include <iostream>
#include <map>
#include <string>
using namespace std;

string minWindow(string s, string t) {


    /// THE STRINGS ARE THE SAME TEHN RETURN ANY
    if(s == t) return t;

    // IF THE SIZE OF S (THAT NEEDS TO BE ALWAYS LONGER) IS LOWER
    // RETURN NULL
    if(s.size() < t.size()) return "";
    // IF ANY ARE EMPTY RETURN NULL
    if(s == "" || t == "") return "";

    // CREATE A MAP TO HAVE THE FREQUENNCY
    map  <char, int>freq_t;


    // FILL IT UP
    for(char c: t) freq_t[c]++;

    // CREATE A MAP, FOR THE FRECUENCY IN THE CURRENT WINDOS (WINDOW IS S[LEF] UNTIL S[RIGHT])
    map  <char, int>freq_win;


    // I USE LEFT, AND RIGHT TO ITERATE, THEN THE MINMUN SIZE TO GET THE MINIMUN STRING
    int left = 0, right =0,
        min_size = INT_MAX,

        // HERRE WE GOT THE COUNT OF HOW MANY  FRECUENCY ARE FOR EACH LETTER,
        // I WILL ITERATE UNTIL Y HAVE NO EQUAL FREQUENCY
        formed = 0,
        required = freq_t.size();

    string min_str = "";

    // I ITERIETE RIGHT UNTIL S.SIZE
    for(;right < s.size(); right++){

        // WHE GET C LIKE THE CURRENT CHAR
        char c = s[right];

        // WE PUT ONLY THE CHARS TAH ARE IN T MAP
        if(freq_t.count(c))
            freq_win[c]++;

        // THEN IF THEY ARE IN BOTH MAPS AND HAVE THE SAME FRECUENCY WE FORMED PLUS ONE
        if(freq_t.count(c) && freq_t[c] ==  freq_win[c]) formed++;


        // THEN WE ITERATE UNTIL FORMED AN REQUIRE WILL NOT BE THE SAME
        while(formed == required){

            // C IS THE CURRENT LEFT
            char c = s[left];

            // IF THE SIZE OF OUR CURRENT SUBSTRING IS LOWER THAN THE MINIMUN THEN WE WILL UPDATE THE MIN STRING
            int cur_size = right - left + 1;
            if(cur_size < min_size){
                min_size = cur_size;
                min_str = s.substr(left, min_size);
            }


            /// WWE WILL REDUCE THE FREQUENCY IF LEFT EQUALS A CHAR THAT ARE IN T MAP
            if(freq_t.count(c))
                freq_win[c]--;


            // IF, IS IN T MAP, AND THE FRECUENCY IS LOWER, THEN WE EILL BREAK
            if(freq_t.count(c) && freq_win[c] < freq_t[c])
                formed--;

            left++;

        }
    }

    return min_str;

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

    cout << "Minimun Window Substring: "<<minWindow(s1,s2)<<endl;


    return 0;
}
