/*
Evaluate Reverse Polish Notation - Medium

You are given an array of strings tokens that represents a valid arithmetic expression in Reverse Polish Notation.
Return the integer that represents the evaluation of the expression.

The operands may be integers or the results of other operations.
The operators include '+', '-', '*', and '/'.
Assume that division between integers always truncates toward zero.

Example 1:
Input: tokens = ["1","2","+","3","*","4","-"]
Output: 5
Explanation: ((1 + 2) * 3) - 4 = 5

Constraints:
1 <= tokens.length <= 1000.
tokens[i] is "+", "-", "*", or "/", or a string representing an integer in the range [-100, 100].


*/
#include <iostream>
#include <vector>
#include <stack>
#include <string>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {

        if(tokens.size() == 1 && isNum(tokens.back())) return stoi(tokens.back());
        if(tokens.size() < 3) return 0;
        if(isOp(tokens[0]) || isOp(tokens[1])) return 0;

        stack<string> operations_;
        stack<int> waiting;

        for(int it = tokens.size() - 1; it >= 0; it--)
            operations_.push(tokens[it]);

        int result = 0, operand_ = 0;
        char operator_ = 0;

        while(!operations_.empty()){

            if (isNum(operations_.top())){
                waiting.push(stoi(operations_.top()));
                operations_.pop();
                continue;
            }

            operand_ = waiting.top();
            waiting.pop();

            result = waiting.top();
            waiting.pop();

            operator_ = operations_.top().back();
            operations_.pop();

            switch(operator_){
            case '+': result += operand_; break;
            case '-': result -= operand_; break;
            case '*': result *= operand_; break;
            case '/': result /= operand_; break;
            }

            waiting.push(result);
        }

        return result;
    }

    bool isNum(const string &num){

        if(num.empty()) return false;

        int start = 0;

        if(num[0] == '-') start = 1;

        if(start == 1 && num.size() == 1) return false;

        for(int i = start; i < num.size(); i++)
            if(num[i] < '0' || num[i] > '9')
                return false;

        return true;
    }

    bool isOp(string operator_){

        char op = operator_.back();

        return (op == '+' || op == '-' || op == '*' || op == '/');
    }
};

int main() {

    Solution sol;

    vector<string> tokens = {"2","1","+","3","*"};

    cout << "Tokens: { ";
    for (string t : tokens) {
        cout << t << " ";
    }
    cout << "}"<< endl;

    int result = sol.evalRPN(tokens);

    cout << "Result: " << result << endl; // 9

    return 0;
}
