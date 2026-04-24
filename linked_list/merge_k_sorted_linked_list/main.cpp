/*
Merge K Sorted Linked Lists - Hard

You are given an array of k linked lists lists, where each list is sorted in ascending order.

Return the sorted linked list that is the result of merging all of the individual linked lists.

Example 1:
Input: lists = [[1,2,4],[1,3,5],[3,6]]
Output: [1,1,2,3,3,4,5,6]

Example 2:
Input: lists = []
Output: []

Example 3:
Input: lists = [[]]
Output: []

Constraints:
    0 <= lists.length <= 1000
    0 <= lists[i].length <= 100
    -1000 <= lists[i][j] <= 1000
*/
#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* mergeKLists(vector<ListNode*>& lists) {

    ListNode *dummy = new ListNode();
    ListNode *it = dummy;

    for(auto *node2 : lists){

        if(!dummy->next){
            dummy->next = node2;
            continue;
        }

        ListNode *node1 = dummy->next;
        dummy->next = nullptr;

        while(node1 && node2){

            if(node1->val <= node2->val){
                it->next = node1;
                node1 = node1->next;
            }else{
                it->next = node2;
                node2 = node2->next;
            }

            it = it->next;
        }

        if(node1 != nullptr ) it->next = node1;
        if(node2 != nullptr ) it->next = node2;

        it = dummy;
    }

    return dummy->next;
}

int main() {

    vector<ListNode*> lists;

    // list 1: 1 -> 4 -> 5
    ListNode *a1 = new ListNode(1);
    a1->next = new ListNode(4);
    a1->next->next = new ListNode(5);

    // list 2: 1 -> 3 -> 4
    ListNode *a2 = new ListNode(1);
    a2->next = new ListNode(3);
    a2->next->next = new ListNode(4);

    // list 3: 2 -> 6
    ListNode *a3 = new ListNode(2);
    a3->next = new ListNode(6);

    lists.push_back(a1);
    lists.push_back(a2);
    lists.push_back(a3);

    ListNode *result = mergeKLists(lists);

    ListNode *curr = result;
    while(curr){
        cout << curr->val;
        if(curr->next) cout << " -> ";
        curr = curr->next;
    }
    cout << endl;

    return 0;
}
