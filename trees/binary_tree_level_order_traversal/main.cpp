/*
Binary Tree Level Order Traversal - Medium

Given a binary tree root, return the level order traversal of it as a nested list, where each sublist contains the values of nodes at a particular level in the tree, from left to right.

Example 1:
Input: root = [1,2,3,4,5,6,7]
Output: [[1],[2,3],[4,5,6,7]]

Example 2:
Input: root = [1]
Output: [[1]]

Example 3:
Input: root = []
Output: []

Constraints:
0 <= The number of nodes in the tree <= 2000.
-1000 <= Node.val <= 1000

*/
#include <iostream>
#include <vector>
#include <queue>
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


    vector<vector<int>> levelOrder(TreeNode* node) {

        if(!node) return {};

        queue < TreeNode* > q;
        q.push(node);

        vector < vector < int > > solution;

        while( !q.empty() ){

            int size = q.size();

            vector<int> level;
            for( int i = 0; i < size; i++ ){

                TreeNode *cur = q.front(); q.pop();

                if(cur->left)  q.push(cur->left);
                if(cur->right) q.push(cur->right);

                level.push_back(cur->val);

            }

            solution.push_back(level);

        }

        return solution;

    }
};

int main() {

    // [1,2,3,4,5,6,7]
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    Solution sol;
    vector<vector<int>> res = sol.levelOrder(root);

    // [[1],[2,3],[4,5,6,7]]
    cout << "[";
    for(int i = 0; i < res.size(); i++){
        cout << "[";
        for(int j = 0; j < res[i].size(); j++){
            cout << res[i][j];
            if(j + 1 < res[i].size()) cout << ",";
        }
        cout << "]";
        if(i + 1 < res.size()) cout << ",";
    }
    cout << "]" << endl;

    return 0;
}
