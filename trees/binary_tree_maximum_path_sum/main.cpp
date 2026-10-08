/*
Binary Tree Maximum Path Sum - Hard

Given the root of a non-empty binary tree, return the maximum path sum of any non-empty path.
A path in a binary tree is a sequence of nodes where each pair of adjacent nodes has an edge connecting them. A node can not appear in the sequence more than once. The path does not necessarily need to include the root.
The path sum of a path is the sum of the node's values in the path.

Example 1:
Input: root = [1,2,3]
Output: 6
Explanation: The path is 2 -> 1 -> 3 with a sum of 2 + 1 + 3 = 6.

Example 2:
Input: root = [-15,10,20,null,null,15,5,-5]
Output: 40
Explanation: The path is 15 -> 20 -> 5 with a sum of 15 + 20 + 5 = 40.

Constraints:
1 <= The number of nodes in the tree <= 30000.
-1000 <= Node.val <= 1000

*/
#include <iostream>
#include <algorithm>
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

    int max_path;

public:


    // The path equal --> secuende of nodes, that didnt repeat.
    // it could star for anyware


    int maxPathSum(TreeNode* root) {

        max_path = INT_MIN;
        dfs( root );
        return max_path;


    }

    int dfs( TreeNode * node ){

        if( !node ) return 0;

        int left  = dfs( node->left );
        int right = dfs( node->right );

        max_path = max( max_path, left + node->val + right);
        max_path = max( max_path, node->val + right);
        max_path = max( max_path, left + node->val);
        max_path = max( max_path, node->val );

        return max( max( node->val + left, node->val + right ), node->val );



    }

};

int main() {

    // [1,2,3]
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    Solution sol;
    cout << sol.maxPathSum(root) << endl; // 6

    return 0;
}
