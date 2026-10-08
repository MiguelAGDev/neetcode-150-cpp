/*
Count Good Nodes In Binary Tree - Medium

Within a binary tree, a node x is considered good if the path from the root of the tree to the node x contains no nodes with a value greater than the value of node x
Given the root of a binary tree root, return the number of good nodes within the tree.

Example 1:
Input: root = [2,1,1,3,null,1,5]
Output: 3

Example 2:
Input: root = [1,2,-1,3,4]
Output: 4

Constraints:
1 <= number of nodes in the tree <= 100,000
-100 <= Node.val <= 100

*/
#include <iostream>
#include <climits>
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

    int good = 0;
    int max_value = INT_MIN;

public:

    // necesita ser dfs

    int goodNodes(TreeNode* node) {

        dfs(node, INT_MIN);

        return good;

    }

    void dfs(TreeNode *node, int max_){

        if(!node) return;

        if(node->val >= max_ ){ good++;  max_ = node->val; }

        dfs( node->left,  max_ );
        dfs( node->right, max_ );

    }
};

int main() {

    // [2,1,1,3,null,1,5]
    TreeNode *root = new TreeNode(2);
    root->left = new TreeNode(1);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(3);
    root->right->left = new TreeNode(1);
    root->right->right = new TreeNode(5);

    Solution sol;
    cout << sol.goodNodes(root) << endl; // 3

    return 0;
}
