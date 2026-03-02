#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

bool isAnagram(string s, string t) {

    if (s.size() != t.size())
        return false;

    unordered_map<char, int> anagram;

    for (char c : s) {
        anagram[c]++;
    }

    for (char c : t) {
        if (anagram.count(c) && anagram[c] > 0)
            anagram[c]--;
        else
            return false;
    }

    return true;
}

int main() {

    string s = "anagram";
    string t = "nagaram";

    if (isAnagram(s, t))
        cout << "Son anagramas" << endl;
    else
        cout << "No son anagramas" << endl;

    return 0;
}
