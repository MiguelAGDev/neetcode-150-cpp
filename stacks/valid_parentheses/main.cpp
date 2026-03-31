/*
Valid Parentheses - Easy

You are given a string s consisting of the following characters: '(', ')', '{', '}', '[' and ']'.

The input string s is valid if and only if:

Every open bracket is closed by the same type of close bracket.
Open brackets are closed in the correct order.
Every close bracket has a corresponding open bracket of the same type.
Return true if s is a valid string, and false otherwise.

Example 1:
Input: s = "[]"
Output: true

Example 2:
Input: s = "([{}])"
Output: true

Example 3:
Input: s = "[(])"
Output: false
Explanation: The brackets are not closed in the correct order.

Constraints:
1 <= s.length <= 1000

*/

#include <iostream>
#include <stack>
using namespace std;

bool isValid(string s) {

    if(s.empty()) return true;
    if(s.size() % 2 ) return false;

    stack <char> brackets;

    for(char c: s){

        if(c == '(' || c == '{' || c == '['){
            brackets.push(c);
            continue;
        }else if(!brackets.empty()){

            char top = brackets.top();

            if(top == '(' && c == ')'
                ||top == '{' && c == '}'
                ||top == '[' && c == ']'){
                brackets.pop();
                continue;
            }

        }

        return false;

    }

    return (brackets.empty());
}

int main()
{
    std::string s;
    cout << "Insert parentheses: ";
    getline(cin,s);
    cout<<endl;

    cout << "Are valid?: "<<isValid(s)<<endl;
    return 0;
}
