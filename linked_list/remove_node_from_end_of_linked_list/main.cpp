/*
Remove Node From End of Linked List - Medium

You are given the beginning of a linked list head, and an integer n.

Remove the nth node from the end of the list and return the beginning of the list.

Example 1:
Input: head = [1,2,3,4], n = 2
Output: [1,2,4]

Example 2:=
Input: head = [5], n = 1
Output: []

Example 3:
Input: head = [1,2], n = 2
Output: [2]

Constraints:
The number of nodes in the list is sz.
1 <= sz <= 30
0 <= Node.val <= 100
1 <= n <= sz
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

ListNode* removeNthFromEnd(ListNode* head, int n) {

    ListNode dummy(0, head);
    ListNode *left, *right;

    left = right = &dummy;

    for(int i = 0; i < n; i++) right = right->next;

    while(right->next){
        left = left->next;
        right = right->next;
    }

    left->next = left->next->next;

    return dummy.next;
}

int main() {
    ListNode *head = nullptr, *tail = nullptr;

    for(int i = 1; i <= 5; i++){
        ListNode *node = new ListNode(i);
        if(!head){ head = node; tail = node; }
        else { tail->next = node; tail = node; }
    }

    ListNode *curr = head;
    while(curr){
        cout << curr->val;
        if(curr->next) cout << " -> ";
        curr = curr->next;
    }
    cout << endl;

    int n = 2;
    head = removeNthFromEnd(head, n);

    curr = head;
    while(curr){
        cout << curr->val;
        if(curr->next) cout << " -> ";
        curr = curr->next;
    }
    cout << endl;

    return 0;
}
