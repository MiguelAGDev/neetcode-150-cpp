#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Tu clase Solution
class Solution {
public:

    string encode(vector<string>& strs) {
        string encode_str = "";
        for(string cword : strs){
            cword = to_string(cword.size()) + '#' + cword;
            encode_str += cword;
        }
        return encode_str;
    }

    vector<string> decode(string s) {
        vector<string> sol_str;
        string numBytes = "";
        int countBytes = 0;
        string curstr = "";

        for(char cchar : s){
            if(countBytes == 0){
                if(cchar != '#'){
                    numBytes += cchar;
                } else {
                    countBytes = stoi(numBytes); // convertir longitud
                    numBytes = "";
                    curstr = "";

                    if(countBytes == 0) {
                        sol_str.push_back("");  // string vacía
                    }
                }
            } else {
                curstr += cchar;
                countBytes--;
                if(countBytes == 0){
                    sol_str.push_back(curstr);
                }
            }
        }
        return sol_str;
    }

};

// Main para probar
int main() {
    Solution codec;

    vector<vector<string>> testCases = {
        {"Hello", "World"},
        {""},
        {"a", "b", "c"},
        {"123", "4567", "89"},
        {"Hello\nWorld", "A\tB C"},
        {"###", "\t\n#"},
        {"12#12#32#43#21#12#21"} // solo para ver comportamiento, no generado por encode
    };

    for (auto &test : testCases) {
        cout << "Original: ";
        for (auto &s : test) cout << "\"" << s << "\" ";
        cout << endl;

        string encoded = codec.encode(test);
        cout << "Encoded: " << encoded << endl;

        vector<string> decoded = codec.decode(encoded);
        cout << "Decoded: ";
        for (auto &s : decoded) cout << "\"" << s << "\" ";
        cout << endl << "--------------------------" << endl;
    }

    return 0;
}
