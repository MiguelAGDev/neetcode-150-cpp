/*
Reorder Linked List - Medium

You are given the head of a singly linked-list.

The positions of a linked list of length = 7 for example, can intially be represented as:
[0, 1, 2, 3, 4, 5, 6]

Reorder the nodes of the linked list to be in the following order:
[0, 6, 1, 5, 2, 4, 3]

Notice that in the general case for a list of length = n the nodes are reordered to be in the following order:
[0, n-1, 1, n-2, 2, n-3, ...]

You may not modify the values in the list's nodes, but instead you must reorder the nodes themselves.

Example 1:
Input: head = [2,4,6,8]
Output: [2,8,4,6]

Example 2:
Input: head = [2,4,6,8,10]
Output: [2,10,4,8,6]

Constraints:
1 <= Length of the list <= 1000.
1 <= Node.val <= 1000
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

void reorderList(ListNode* head) {

    ListNode *slow = head, *fast = head;

    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
    }

    ListNode *second = slow->next;
    slow->next = nullptr;

    ListNode* mid = nullptr;

    while(second){

        ListNode* next = second->next;
        second->next = mid;
        mid = second;
        second = next;

    }

    ListNode *it = head;
    while(mid){
        ListNode *mid_next = mid->next;
        ListNode *head_next = it->next;

        it->next = mid;
        mid->next = head_next;

        mid = mid_next;
        it = head_next;

    }
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

    reorderList(head);

    curr = head;
    while(curr){
        cout << curr->val;
        if(curr->next) cout << " -> ";
        curr = curr->next;
    }
    cout << endl;

    return 0;
}
