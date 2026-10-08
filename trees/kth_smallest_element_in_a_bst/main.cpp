/*
Kth Smallest Element In a Bst - Medium

Given the root of a binary search tree, and an integer k, return the kth smallest value (1-indexed) in the tree.
A binary search tree satisfies the following constraints:

The left subtree of every node contains only nodes with keys less than the node's key.
The right subtree of every node contains only nodes with keys greater than the node's key.
Both the left and right subtrees are also binary search trees.

Example 1:
Input: root = [2,1,3], k = 1
Output: 1

Example 2:
Input: root = [4,3,5,2,null], k = 4
Output: 5

Constraints:
1 <= k <= The number of nodes in the tree <= 10,000.
0 <= Node.val <= 10,000

*/
#include <iostream>
#include <vector>
#include <queue>
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
    int kthSmallest(TreeNode* node, int k) {

        if(!node) return -1;

        queue < TreeNode * > q;
        q.push(node);

        vector< int > solution;

        while( !q.empty() ){

            TreeNode *cur = q.front(); q.pop();

            if(cur->left)  q.push(cur->left);
            if(cur->right) q.push(cur->right);

            solution.push_back(cur->val);

        }

        sort(solution.begin(), solution.end());

        return solution[k - 1];

    }
};

int main() {

    // [2,1,3]
    TreeNode *root = new TreeNode(2);
    root->left = new TreeNode(1);
    root->right = new TreeNode(3);

    int k = 1;

    Solution sol;
    cout << sol.kthSmallest(root, k) << endl; // 1

    return 0;
}
