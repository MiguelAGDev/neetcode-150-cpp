/*
Reverse Nodes in K-Group - Hard

You are given the head of a singly linked list head and a positive integer k.

You must reverse the first k nodes in the linked list, and then reverse the next k nodes, and so on. If there are fewer than k nodes left, leave the nodes as they are.

Return the modified list after reversing the nodes in each group of k.

You are only allowed to modify the nodes' next pointers, not the values of the nodes.

Example 1:
Input: head = [1,2,3,4,5,6], k = 3
Output: [3,2,1,6,5,4]

Example 2:
Input: head = [1,2,3,4,5], k = 3
Output: [3,2,1,4,5]

Constraints:
    The length of the linked list is n.
    1 <= k <= n <= 100
    0 <= Node.val <= 100

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

ListNode* reverseKGroup(ListNode* head, int k) {

    int num_nodes = 0;
    ListNode* it = head;

    while (it) {
        num_nodes++;
        it = it->next;
    }

    int total_groups = num_nodes / k;

    ListNode* dummy = new ListNode(-1, head);
    ListNode* groupPrev = dummy;

    while (total_groups--) {

        ListNode* con = head;
        ListNode* prev = nullptr;
        int count = k;

        while (count--) {
            ListNode* next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }

        groupPrev->next = prev;
        con->next = head;

        groupPrev = con;
    }

    return dummy->next;
}

int main() {

    ListNode *head = nullptr, *tail = nullptr;

    for(int i = 1; i <= 6; i++){
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

    int k = 2;
    head = reverseKGroup(head, k);

    curr = head;
    while(curr){
        cout << curr->val;
        if(curr->next) cout << " -> ";
        curr = curr->next;
    }
    cout << endl;

    return 0;
}


