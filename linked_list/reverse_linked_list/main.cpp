/*

Reverse Linked List - Easy

Given the beginning of a singly linked list head, reverse the list, and return the new beginning of the list.

Example 1:
Input: head = [0,1,2,3]
Output: [3,2,1,0]

Example 2:
Input: head = []
Output: []

Constraints:

0 <= The length of the list <= 1000.
-1000 <= Node.val <= 1000

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

ListNode* reverseList(ListNode* head) {

    ListNode *rev_head = nullptr;

    while(head){
        ListNode *next = head->next;
        head->next = rev_head;
        rev_head = head;
        head = next;
    }

    return rev_head;
}

int main() {

    int size = 10;
    ListNode *head = nullptr;
    ListNode *tail = nullptr;

    for(int i = 1; i <= size; i++){
        ListNode *node = new ListNode(i);
        if(!head){
            head = node;
            tail = node;
        } else {
            tail->next = node;
            tail = node;
        }
    }

    // Imprimir lista inicial
    ListNode *curr = head;
    while(curr){
        cout << curr->val;
        if(curr->next) cout << " -> ";
        curr = curr->next;
    }
    cout << endl;

    // Resultado
    ListNode *result = reverseList(head);
    curr = result;
    while(curr){
        cout << curr->val;
        if(curr->next) cout << " -> ";
        curr = curr->next;
    }
    cout << endl;

    return 0;
}
