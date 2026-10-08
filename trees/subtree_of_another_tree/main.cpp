/*
Subtree of Another Tree - Easy

Given the roots of two binary trees root and subRoot, return true if there is a subtree of root with the same structure and node values of subRoot and false otherwise.
A subtree of a binary tree tree is a tree that consists of a node in tree and all of this node's descendants. The tree tree could also be considered as a subtree of itself.

Example 1:
Input: root = [1,2,3,4,5], subRoot = [2,4,5]
Output: true

Example 2:
Input: root = [1,2,3,4,5,null,null,6], subRoot = [2,4,5]
Output: false

Constraints:
The number of nodes in the root tree is in the range [1, 2000].
The number of nodes in the subRoot tree is in the range [1, 1000].
-10^4 <= root.val <= 10^4
-10^4 <= subRoot.val <= 10^4

*/
#include <iostream>
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
    bool isSubtree(TreeNode* node, TreeNode* subNode) {

        if(!node) return false;

        if(isSameTree(node, subNode)) return true;

        return isSubtree(node->left, subNode) || isSubtree(node->right, subNode);
    }

    bool isSameTree(TreeNode* p, TreeNode* q) {

        if(!p && !q) return true;
        else if((!p && q) || (p && !q)) return false;

        return p->val == q->val && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};

int main() {

    // root = [1,2,3,4,5]
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    // subRoot = [2,4,5]
    TreeNode *subRoot = new TreeNode(2);
    subRoot->left = new TreeNode(4);
    subRoot->right = new TreeNode(5);

    Solution sol;
    cout << (sol.isSubtree(root, subRoot) ? "true" : "false") << endl; // true

    return 0;
}
