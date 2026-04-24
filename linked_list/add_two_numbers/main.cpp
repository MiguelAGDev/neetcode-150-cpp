/*

Add Two Numbers - Medium

You are given two non-empty linked lists, l1 and l2, where each represents a non-negative integer.

The digits are stored in reverse order, e.g. the number 321 is represented as 1 -> 2 -> 3 -> in the linked list.

Each of the nodes contains a single digit. You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Return the sum of the two numbers as a linked list.

Example 1: https://imagedelivery.net/CLfkmk9Wzy8_9HRyug4EVA/fee72e19-6a21-45a5-365e-3cb45aba9700/public
Input: l1 = [1,2,3], l2 = [4,5,6]
Output: [5,7,9]

Explanation: 321 + 654 = 975.

Example 2:
Input: l1 = [9], l2 = [9]
Output: [8,1]

Constraints:
1 <= l1.length, l2.length <= 100.
0 <= Node.val <= 9
*/
#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

    ListNode *result = new ListNode (-1);
    ListNode *it = result;

    int count = 0;
    while(l1 || l2){

        int x = (l1)? l1->val: 0;
        int y = (l2)? l2->val: 0;

        int sum = x + y + count;

        (sum/10)? count = 1 : count = 0;

        it->next = new ListNode(sum % 10);

        it = it->next;
        l1 = (l1) ? l1->next: nullptr;
        l2 = (l2) ? l2->next: nullptr;
    }

    if(count) it->next = new ListNode(count);

    return result->next;
}

int main() {

    ListNode *l1 = nullptr, *t1 = nullptr;
    ListNode *l2 = nullptr, *t2 = nullptr;

    int a[] = {2,4,3};
    int b[] = {5,6,4};

    for(int i = 0; i < 3; i++){
        ListNode *node = new ListNode(a[i]);
        if(!l1){ l1 = node; t1 = node; }
        else { t1->next = node; t1 = node; }
    }

    for(int i = 0; i < 3; i++){
        ListNode *node = new ListNode(b[i]);
        if(!l2){ l2 = node; t2 = node; }
        else { t2->next = node; t2 = node; }
    }

    ListNode *curr = l1;
    while(curr){
        cout << curr->val;
        if(curr->next) cout << " -> ";
        curr = curr->next;
    }
    cout << endl;

    curr = l2;
    while(curr){
        cout << curr->val;
        if(curr->next) cout << " -> ";
        curr = curr->next;
    }
    cout << endl;

    ListNode *result = addTwoNumbers(l1, l2);

    curr = result;
    while(curr){
        cout << curr->val;
        if(curr->next) cout << " -> ";
        curr = curr->next;
    }
    cout << endl;

    return 0;
}
