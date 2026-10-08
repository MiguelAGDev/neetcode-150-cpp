/*
Lowest Common Ancestor of a Binary Search Tree - Medium

Given a binary search tree (BST) where all node values are unique, and two nodes from the tree p and q, return the lowest common ancestor (LCA) of the two nodes.
The lowest common ancestor between two nodes p and q is the lowest node in a tree T such that both p and q are descendants. The ancestor is allowed to be a descendant of itself.

Example 1:
Input: root = [5,3,8,1,4,7,9,null,2], p = 3, q = 8
Output: 5

Example 2:
Input: root = [5,3,8,1,4,7,9,null,2], p = 3, q = 4
Output: 3
Explanation: The LCA of nodes 3 and 4 is 3, since a node can be a descendant of itself.

Constraints:
2 <= The number of nodes in the tree <= 100.
-100 <= Node.val <= 100
p != q
p and q will both exist in the BST.

*/
#include <iostream>
#include <algorithm>
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
    TreeNode* lowestCommonAncestor(TreeNode* node, TreeNode* p, TreeNode* q) {

        if(p > q) swap(p,q);
        return bfs(node, p->val, q->val);

    }

    TreeNode *bfs(TreeNode *node, int p, int q){

        if(!node) return nullptr;

        int value = node->val;

        if(p < value && q < value) return bfs(node->left, p, q);
        if(p > value && q > value) return bfs(node->right, p, q);

        return node;
    }
};

int main() {

    // [5,3,8,1,4,7,9,null,2]
    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(7);
    root->right->right = new TreeNode(9);
    root->left->left->right = new TreeNode(2);

    TreeNode *p = root->left;  // 3
    TreeNode *q = root->right; // 8

    Solution sol;
    cout << sol.lowestCommonAncestor(root, p, q)->val << endl; // 5

    return 0;
}
