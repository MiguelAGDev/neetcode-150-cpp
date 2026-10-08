/*
Balanced Binary Tree - Easy

Given a binary tree, return true if it is height-balanced and false otherwise.
A height-balanced binary tree is defined as a binary tree in which the left and right subtrees of every node differ in height by no more than 1.

Example 1:
Input: root = [1,2,3,null,null,4]
Output: true

Example 2:
Input: root = [1,2,3,null,null,4,null,5]
Output: false

Example 3:
Input: root = []
Output: true

Constraints:
The number of nodes in the tree is in the range [0, 1000].
-1000 <= Node.val <= 1000

*/
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool isBalanced(TreeNode* node) {

        if(!node) return true;

        int left = dfs(node->left);
        int right = dfs(node->right);

        if(abs(left - right) > 1) return false;

        return isBalanced(node->left) && isBalanced(node->right);

    }


    int dfs(TreeNode *node){
        if(!node) return 0;

        int right = dfs(node->right);
        int left = dfs(node->left);

        return 1 + max(left, right);
    }
};

int main() {

    // [1,2,3,null,null,4]
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(4);

    Solution sol;
    cout << (sol.isBalanced(root) ? "true" : "false") << endl; // true

    return 0;
}
