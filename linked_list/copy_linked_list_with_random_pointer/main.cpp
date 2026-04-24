/*
Copy Linked List with Random Pointer - Medium

You are given the head of a linked list of length n. Unlike a singly linked list, each node contains an additional pointer random, which may point to any node in the list, or null.

    -Create a deep copy of the list.

    -The deep copy should consist of exactly n new nodes, each including:

    -The original value val of the copied node
    A next pointer to the new node corresponding to the next pointer of the original node
    A random pointer to the new node corresponding to the random pointer of the original node

Note: None of the pointers in the new list should point to nodes in the original list.

Return the head of the copied linked list.

In the examples, the linked list is represented as a list of n nodes. Each node is represented as a pair of [val, random_index] where random_index is the index of the node (0-indexed) that the random pointer points to, or null if it does not point to any node.

Example 1: https://imagedelivery.net/CLfkmk9Wzy8_9HRyug4EVA/5a5c2bdd-51e2-4795-4544-096af4b6cc00/public
Input: head = [[3,null],[7,3],[4,0],[5,1]]
Output: [[3,null],[7,3],[4,0],[5,1]]

Example 2: https://imagedelivery.net/CLfkmk9Wzy8_9HRyug4EVA/6e56fa98-cf1e-4ca6-18d4-716dac4ba900/public
Input: head = [[1,null],[2,2],[3,2]]
Output: [[1,null],[2,2],[3,2]]

Constraints:
0 <= n <= 100
-100 <= Node.val <= 100
random is null or is pointing to some node in the linked list.

*/
#include <iostream>
#include <unordered_map>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

Node* copyRandomList(Node* head) {

    unordered_map <Node *, Node *> random_map;
    Node *itHead = head;

    while(itHead){

        random_map[itHead] = itHead->random;

        Node *copy = new Node(itHead->val);
        copy->next = itHead->next;
        itHead->next = copy;

        itHead = copy->next;
    }

    itHead = head;
    while(itHead && itHead->next){

        if(!random_map[itHead]){
            itHead = itHead->next->next;
            continue;
        }

        Node *copy = itHead->next;
        copy->random =  random_map[itHead]->next;

        itHead = itHead->next->next;
    }

    itHead = head;
    Node *deepCopy = new Node(-1);
    Node *itCopy = deepCopy;

    while(itHead && itHead->next){

        Node *next = itHead->next;
        itHead->next = itHead->next->next;

        itCopy->next = next;
        itCopy = itCopy->next;
        itHead = itHead->next;
    }

    return deepCopy->next;
}

int main() {

    Node* n1 = new Node(1);
    Node* n2 = new Node(2);
    Node* n3 = new Node(3);

    n1->next = n2;
    n2->next = n3;

    n1->random = n3;
    n2->random = n1;
    n3->random = nullptr;

    Node* head = n1;

    Node* copied = copyRandomList(head);

    Node* curr = copied;
    while(curr){
        cout << "Val: " << curr->val;
        if(curr->random) cout << ", Random: " << curr->random->val;
        else cout << ", Random: null";
        cout << endl;
        curr = curr->next;
    }

    return 0;
}
