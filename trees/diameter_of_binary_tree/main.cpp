/*
Diameter of Binary Tree - Easy

The diameter of a binary tree is defined as the length of the longest path between any two nodes within the tree. The path does not necessarily have to pass through the root.
The length of a path between two nodes in a binary tree is the number of edges between the nodes. Note that the path can not include the same node twice.
Given the root of a binary tree root, return the diameter of the tree.

Example 1:
Input: root = [1,null,2,3,4,5]
Output: 3
Explanation: 3 is the length of the path [1,2,3,5] or [5,3,2,4].

Example 2:
Input: root = [1,2,3]
Output: 2

Constraints:
1 <= number of nodes in the tree <= 100
-100 <= Node.val <= 100

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

    int max_ = 0;

    int diameterOfBinaryTree(TreeNode* root) {

        max_ = 0;
        dfs(root);
        return max_;


    }

    int dfs( TreeNode *node ){

        if( !node ) return 0;

        max_ = max(max_, dfs(node->left) + dfs(node->right));

        return 1 + max(dfs(node->left) , dfs(node->right));


    };
};

int main() {

    // [1,null,2,3,4,5]
    TreeNode *root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);
    root->right->right = new TreeNode(4);
    root->right->left->left = new TreeNode(5);

    Solution sol;
    cout << sol.diameterOfBinaryTree(root) << endl; // 3

    return 0;
}
