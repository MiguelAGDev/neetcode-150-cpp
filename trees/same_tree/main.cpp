/*
Same Tree - Easy

Given the roots of two binary trees p and q, return true if the trees are equivalent, otherwise return false.
Two binary trees are considered equivalent if they share the exact same structure and the nodes have the same values.

Example 1:
Input: p = [1,2,3], q = [1,2,3]
Output: true

Example 2:
Input: p = [4,7], q = [4,null,7]
Output: false

Example 3:
Input: p = [1,2,3], q = [1,3,2]
Output: false

Constraints:
0 <= The number of nodes in both trees <= 100.
-100 <= Node.val <= 100

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
    bool isSameTree(TreeNode* p, TreeNode* q) {

        if(!p && !q) return true;
        else if((!p && q) || (p && !q)) return false;

        return p->val == q->val && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};

int main() {

    // p = [1,2,3]
    TreeNode *p = new TreeNode(1);
    p->left = new TreeNode(2);
    p->right = new TreeNode(3);

    // q = [1,2,3]
    TreeNode *q = new TreeNode(1);
    q->left = new TreeNode(2);
    q->right = new TreeNode(3);

    Solution sol;
    cout << (sol.isSameTree(p, q) ? "true" : "false") << endl; // true

    return 0;
}
