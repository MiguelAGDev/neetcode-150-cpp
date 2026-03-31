/*
Min Stack - Medium

Design a stack class that supports the push, pop, top, and getMin operations.

MinStack() initializes the stack object.
void push(int val) pushes the element val onto the stack.
void pop() removes the element on the top of the stack.
int top() gets the top element of the stack.
int getMin() retrieves the minimum element in the stack.
Each function should run in  O(1) time.

Example 1:

Input: ["MinStack", "push", 1, "push", 2, "push", 0, "getMin", "pop", "top", "getMin"]
Output: [null,null,null,null,0,null,2,1]

Explanation:
MinStack minStack = new MinStack();
minStack.push(1);
minStack.push(2);
minStack.push(0);
minStack.getMin(); // return 0
minStack.pop();
minStack.top();    // return 2
minStack.getMin(); // return 1

Constraints:
-2^31 <= val <= 2^31 - 1.
pop, top and getMin will always be called on non-empty stacks.


*/
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class MinStack {

    vector<int> stack_;
    vector<int> cur_min;
    int min = INT_MAX;

public:
    MinStack() {}

    void push(int val) {

        stack_.push_back(val);

        if(stack_.size() == 1){
            min = stack_.back();
            cur_min.push_back(val);
            return;

        }else if(min < val){

            cur_min.push_back(min);
            cur_min[cur_min.size() - 2] = val;
            return;

        }else if(min >= val){

            min = val;
            cur_min.push_back(min);
            return;
        }
    }

    void pop() {

        if(stack_.back() == cur_min.back()){
            cur_min.pop_back();
            min = cur_min.back();
        }else{
            cur_min[cur_min.size() - 2] = min;
            cur_min.pop_back();
        }

        stack_.pop_back();
    }

    int top() {
        return stack_.back();
    }

    int getMin() {
        return min;
    }
};

int main() {

    MinStack st;

    st.push(-2);
    st.push(0);
    st.push(-3);

    cout << "Current min: " << st.getMin() << endl; // -3

    st.pop();

    cout << "Top element: " << st.top() << endl; // 0
    cout << "Current min: " << st.getMin() << endl; // -2

    return 0;
}
