
/*
LRU Cache - Medium

Implement the Least Recently Used (LRU) cache class LRUCache. The class should support the following operations

LRUCache(int capacity) Initialize the LRU cache of size capacity.
int get(int key) Return the value corresponding to the key if the key exists, otherwise return -1.
void put(int key, int value) Update the value of the key if the key exists. Otherwise, add the key-value pair to the cache. If the introduction of the new pair causes the cache to exceed its capacity, remove the least recently used key.
A key is considered used if a get or a put operation is called on it.

Ensure that get and put each run in O(1) average time complexity.

Example 1:
Input:
["LRUCache", [2], "put", [1, 10],  "get", [1], "put", [2, 20], "put", [3, 30], "get", [2], "get", [1]]
Output:
[null, null, 10, null, null, 20, -1]

Explanation:
    LRUCache lRUCache = new LRUCache(2);
    lRUCache.put(1, 10);  // cache: {1=10}
    lRUCache.get(1);      // return 10
    lRUCache.put(2, 20);  // cache: {1=10, 2=20}
    lRUCache.put(3, 30);  // cache: {2=20, 3=30}, key=1 was evicted
    lRUCache.get(2);      // returns 20
    lRUCache.get(1);      // return -1 (not found)

Constraints:
1 <= capacity <= 100
0 <= key <= 1000
0 <= value <= 1000
*/
#include <iostream>
#include <unordered_map>
using namespace std;

struct Node {
    int key;
    int val;
    Node* next;
    Node* prev;

    Node(int k = 0, int v = 0) : key(k), val(v), next(nullptr), prev(nullptr) {}
};

class LRUCache {

    unordered_map<int, Node*> nodeMap;
    Node* head;
    Node* tail;
    int maxSize;

public:
    LRUCache(int capacity) {
        maxSize = capacity;

        head = new Node();
        tail = new Node();

        head->next = tail;
        tail->prev = head;
    }

    void remove(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void insertFront(Node* node) {
        node->next = head->next;
        node->prev = head;

        head->next->prev = node;
        head->next = node;
    }

    int get(int key) {
        if (!nodeMap.count(key)) return -1;

        Node* node = nodeMap[key];
        remove(node);
        insertFront(node);

        return node->val;
    }

    void put(int key, int value) {

        if (nodeMap.count(key)) {
            Node* node = nodeMap[key];
            node->val = value;

            remove(node);
            insertFront(node);
            return;
        }

        if (nodeMap.size() == maxSize) {
            Node* lru = tail->prev;

            remove(lru);
            nodeMap.erase(lru->key);
            delete lru;
        }

        Node* newNode = new Node(key, value);
        insertFront(newNode);
        nodeMap[key] = newNode;
    }
};

int main() {

    LRUCache cache(2);

    cache.put(1, 1);
    cache.put(2, 2);

    cout << cache.get(1) << endl; // 1

    cache.put(3, 3); // evicts key 2

    cout << cache.get(2) << endl; // -1

    cache.put(4, 4); // evicts key 1

    cout << cache.get(1) << endl; // -1
    cout << cache.get(3) << endl; // 3
    cout << cache.get(4) << endl; // 4

    return 0;
}
