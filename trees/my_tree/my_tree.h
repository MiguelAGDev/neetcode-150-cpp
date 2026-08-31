#ifndef MY_TREE_H
#define MY_TREE_H

#include <queue>
#include <iostream>
#include <algorithm>

/// NODE
struct Node {
    int val;
    Node* left;
    Node* right;

    Node(int v) : val(v), left(nullptr), right(nullptr) {}
};


/// BINARY SEARCH TREE
class BST {

public:
    BST() : root(nullptr) {}

    ~BST() {
        destroy(root);
    }

    // EXCERSICE

    int findMin(){ return findMin(root); }

    int findMax(){ return findMax(root); }

    int countNodes(){ return countNodes(root); }

    int countLeaves(){ return countLeaves(root); }

    int sumNodes(){ return sumNodes(root); }

    bool existInRange(int left, int right){ return existInRange(root,  left, right); }

    // PUBLIC API
    void insert(int val) { root = insert(root, val); }

    bool search(int val) { return search(root, val); }

    void remove(int val) { root = remove(root, val); }

    int height() { return height(root); }

    void inorder() { inorder(root); std::cout << "\n"; }

    void preorder() { preorder(root); std::cout << "\n"; }

    void postorder() { postorder(root); std::cout << "\n"; }

    void levelOrder() {
        if (!root) return;

        std::queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            int size = q.size();

            for (int i = 0; i < size; i++) {
                Node* cur = q.front(); q.pop();
                std::cout << cur->val << " ";

                if (cur->left)  q.push(cur->left);
                if (cur->right) q.push(cur->right);
            }
            std::cout << "\n";
        }
    }

private:
    Node* root;

    // EXERSICE
    int findMin(Node* node){
        if(!node->left) return node->val;
        return findMin(node->left);
    }

    int findMax(Node *node){

        if(!node->right) return node->val;
        return findMax(node->right);

    }

    int countNodes(Node *node){

        if(!node) return 0;
        return 1 + countNodes(node->left) + countNodes(node->right);
    }


    int countLeaves(Node *node){

        if(!node) return 0;

        if(!node->left && !node->right) return 1;

        return countLeaves(node->left) + countLeaves(node->right);
    }

    int sumNodes(Node *node){

        if(!node) return 0;

        return node->val + sumNodes(node->left) + sumNodes(node ->right);
    }

    bool existInRange(Node *node, int left, int right){

        if(!node) return false;

        if(node->val >= left && node->val <= right)
            return true;
        // Caso 2: nodo muy pequeño → ignora izquierda
        if(node->val < left)
            return existInRange(node->right, left, right);

        // Caso 3: nodo muy grande → ignora derecha
        if(node->val > right)
            return existInRange(node->left, left, right);

        return false; // por seguridad (aunque no debería llegar aquí)
    }

    // INSERT
    Node* insert(Node* node, int val) {
        if (!node) return new Node(val);

        if (val < node->val)
            node->left = insert(node->left, val);
        else if (val > node->val)
            node->right = insert(node->right, val);

        return node;
    }

    // SEARCH
    bool search(Node* node, int val) {
        if (!node) return false;

        if (node->val == val) return true;

        if (val < node->val)
            return search(node->left, val);
        else
            return search(node->right, val);
    }

    // MIN NODE
    Node* minNode(Node* node) {
        while (node->left) node = node->left;
        return node;
    }

    // REMOVE
    Node* remove(Node* node, int val) {
        if (!node) return nullptr;

        if (val < node->val) {
            node->left = remove(node->left, val);
        }
        else if (val > node->val) {
            node->right = remove(node->right, val);
        }
        else {
            // CASE 1: leaf
            if (!node->left && !node->right) {
                delete node;
                return nullptr;
            }

            // CASE 2: one child
            if (!node->left) {
                Node* tmp = node->right;
                delete node;
                return tmp;
            }

            if (!node->right) {
                Node* tmp = node->left;
                delete node;
                return tmp;
            }

            // CASE 3: two children
            Node* successor = minNode(node->right);
            node->val = successor->val;
            node->right = remove(node->right, successor->val);
        }

        return node;
    }

    // HEIGHT
    int height(Node* node) {
        if (!node) return 0;
        return 1 + std::max(height(node->left), height(node->right));
    }

    // TRAVERSALS
    void preorder(Node* node) {
        if (!node) return;
        std::cout << node->val << " ";
        preorder(node->left);
        preorder(node->right);
    }

    void inorder(Node* node) {
        if (!node) return;
        inorder(node->left);
        std::cout << node->val << " ";
        inorder(node->right);
    }

    void postorder(Node* node) {
        if (!node) return;
        postorder(node->left);
        postorder(node->right);
        std::cout << node->val << " ";
    }

    // DESTROY
    void destroy(Node* node) {
        if (!node) return;
        destroy(node->left);
        destroy(node->right);
        delete node;
    }
};

#endif // MY_TREE_H
