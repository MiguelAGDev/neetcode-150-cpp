/*

Merge Two Sorted Linked Lists - Easy

You are given the heads of two sorted linked lists list1 and list2.
Merge the two lists into one sorted linked list and return the head of the new sorted linked list.

The new list should be made up of nodes from list1 and list2.

Example 1: https://imagedelivery.net/CLfkmk9Wzy8_9HRyug4EVA/51adfea9-493a-4abb-ece7-fbb359d1c800/public
Input: list1 = [1,2,4], list2 = [1,3,5]
Output: [1,1,2,3,4,5]

Example 2:
Input: list1 = [], list2 = [1,2]
Output: [1,2]

Example 3:
Input: list1 = [], list2 = []
Output: []

Constraints:
0 <= The length of the each list <= 100.
-100 <= Node.val <= 100

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

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

    ListNode dummy;
    ListNode *tail = &dummy;

    while(list1 && list2){

        if(list1->val < list2->val){
            tail->next = list1;
            list1 = list1->next;
        } else {
            tail->next = list2;
            list2 = list2->next;
        }

        tail = tail->next;
    }

    tail->next = list1 ? list1 : list2;

    return dummy.next; // fix: no &dummy

}

int main() {

    int size = 5;
    ListNode *head1 = nullptr, *tail1 = nullptr;
    ListNode *head2 = nullptr, *tail2 = nullptr;

    for(int i = 1; i <= size; i++){
        ListNode *node = new ListNode(i * 2 - 1); // 1,3,5,7,9
        if(!head1){ head1 = node; tail1 = node; }
        else { tail1->next = node; tail1 = node; }
    }

    for(int i = 1; i <= size; i++){
        ListNode *node = new ListNode(i * 2); // 2,4,6,8,10
        if(!head2){ head2 = node; tail2 = node; }
        else { tail2->next = node; tail2 = node; }
    }

    // Imprimir listas iniciales
    ListNode *curr = head1;
    while(curr){ cout << curr->val; if(curr->next) cout << " -> "; curr = curr->next; }
    cout << endl;

    curr = head2;
    while(curr){ cout << curr->val; if(curr->next) cout << " -> "; curr = curr->next; }
    cout << endl;

    // Resultado
    ListNode *result = mergeTwoLists(head1, head2);
    curr = result;
    while(curr){ cout << curr->val; if(curr->next) cout << " -> "; curr = curr->next; }
    cout << endl;

    return 0;
}
