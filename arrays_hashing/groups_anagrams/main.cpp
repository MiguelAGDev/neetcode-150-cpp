#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        unordered_map <string, int> seen;
        vector<vector<string>> groups;

        for(string s: strs){
            seen[s];
        }

        int i = -1, j = 0;
        string w1, w2;
        for(string s: strs){

            i++;
            j = i + 1;

            if(seen[s] == 0){
                w1 = s;
                groups.push_back(vector<string>());
                groups.back().push_back(w1);
                seen[s] = 1;

                while(j < strs.size()){
                    w2 = strs[j];

                    if(w1.size() != w2.size()) {
                        j++; continue;
                    }

                    unordered_map <char, int> anagram;

                    for(char c: w1){
                        anagram[c]++;
                    }

                    bool isAnagram = true;
                    for(char c: w2){
                        if(anagram.count(c) && anagram[c] > 0)
                            anagram[c]--;
                        else{
                            isAnagram = false;
                            break;
                        }
                    }

                    if(!isAnagram){
                        j++;
                        continue;
                    }

                    groups.back().push_back(w2);
                    seen[w2] = 1;
                    j++;
                }
            }
        }

        return groups;
    }
};

int main() {
    Solution sol;

    vector<string> strs = {"eat","tea","tan","ate","nat","bat"};

    vector<vector<string>> result = sol.groupAnagrams(strs);

    for (const auto& group : result) {
        cout << "[ ";
        for (const auto& word : group) {
            cout << word << " ";
        }
        cout << "]\n";
    }

    return 0;
}
