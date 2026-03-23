

/**
 * Given a string s, return true if it is a palindrome, otherwise return false.

    A palindrome is a string that reads the same forward and backward. It is also case-insensitive and ignores all non-alphanumeric characters.

    Note: Alphanumeric characters consist of letters (A-Z, a-z) and numbers (0-9).

    Example 1:

    Input: s = "Was it a car or a cat I saw?"

    Output: true
    Explanation: After considering only alphanumerical characters we have "wasitacaroracatisaw", which is a palindrome.

    Example 2:

    Input: s = "tab a cat"

    Output: false
    Explanation: "tabacat" is not a palindrome.

    Constraints:

    1 <= s.length <= 1000
    s is made up of only printable ASCII characters.
 *
 */


#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {

        int left = 0, right = s.size() - 1;

        while(left < right){
            while(left < right && !isAlnum(s[left])) ++left;
            while(left < right && !isAlnum(s[right])) --right;

            if(toupper(s[left]) != toupper(s[right]))
                return false;

            ++left;
            --right;
        }

        return true;
    }

    bool isAlnum(char c){
        return ((c >= 'a' && c  <= 'z') ||
                (c >= 'A' && c <= 'Z') ||
                (c >= '0' && c <= '9'));
    }
};

int main() {
    Solution sol;

    // Casos de prueba
    string tests[] = {
        "A man, a plan, a canal: Panama",
        "race a car",
        "No 'x' in Nixon",
        "!!!@@@###$$$",
        "0P",
        "12321",
        "abc$CBA"
    };

    for(const string &s : tests) {
        cout << "\"" << s << "\" -> "
             << (sol.isPalindrome(s) ? "true" : "false") << endl;
    }

    return 0;
}
