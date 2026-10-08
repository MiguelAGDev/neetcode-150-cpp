/*
Binary Tree Right Side View - Medium

You are given the root of a binary tree. Return only the values of the nodes that are visible from the right side of the tree, ordered from top to bottom.

Example 1:
Input: root = [1,2,3,null,4,null,5]
Output: [1,3,5]

Example 2:
Input: root = [1,2,3,4,null,null,null,5]
Output: [1,3,4,5]

Example 3:
Input: root = [1,null,2]
Output: [1,2]

Example 4:
Input: root = []
Output: []

Constraints:
0 <= number of nodes in the tree <= 100
-100 <= Node.val <= 100

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
    vector<int> rightSideView(TreeNode* node) {

        if(!node) return {};

        queue < TreeNode * > q;
        q.push(node);

        vector < int > solution;

        while( !q.empty() ){

            int size = q.size();
            solution.push_back(q.back()->val);

            for( int i = 0; i < size; i++ ){

                TreeNode *cur = q.front();
                q.pop();

                if( cur->left  ) q.push(cur->left);
                if( cur->right ) q.push(cur->right);
            }

        }

        return solution;

    }
};

int main() {

    // [1,2,3,null,4,null,5]
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(5);

    Solution sol;
    vector<int> res = sol.rightSideView(root);

    // [1,3,5]
    cout << "[";
    for(int i = 0; i < res.size(); i++){
        cout << res[i];
        if(i + 1 < res.size()) cout << ",";
    }
    cout << "]" << endl;

    return 0;
}
