/*
Construct Binary Tree From Preorder And Inorder Traversal - Medium

You are given two integer arrays preorder and inorder.

preorder is the preorder traversal of a binary tree
inorder is the inorder traversal of the same tree
Both arrays are of the same size and consist of unique values.

Rebuild the binary tree from the preorder and inorder traversals and return its root.

Example 1:
Input: preorder = [1,2,3,4], inorder = [2,1,3,4]
Output: [1,2,3,null,null,null,4]

Example 2:
Input: preorder = [1], inorder = [1]
Output: [1]

Constraints:
1 <= inorder.length <= 2001.
inorder.length == preorder.length
-1000 <= preorder[i], inorder[i] <= 1000

*/
#include <iostream>
#include <vector>
#include <unordered_map>
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

    unordered_map <int, int> in_map;

public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

        in_map.clear();

        for(int i = 0; i < inorder.size(); i++)
            in_map[inorder[i]] = i;

        return build(
            preorder, 0, inorder.size() - 1,
            inorder,  0, preorder.size() - 1
        );

    }

    TreeNode *build (
                     vector<int> preorder, int pre_left, int pre_right,
                     vector<int> inorder,  int in_left,  int in_right
                    ){

        if(pre_left > pre_right) return nullptr;

        int root_val  = preorder[pre_left];
        int root_index = in_map[root_val];
        int left_size = root_index - in_left;

        TreeNode * root = new TreeNode( root_val );

        root->left = build(
            preorder, pre_left  + 1, pre_left + left_size,
            inorder,  in_left,       root_index - 1
        );

        root->right = build(
            preorder, pre_left + left_size + 1, pre_right,
            inorder,  root_index + 1,              in_right
        );

        return root;







    }
};

void printPreorder(TreeNode *node){
    if(!node){ cout << "null "; return; }
    cout << node->val << " ";
    printPreorder(node->left);
    printPreorder(node->right);
}

int main() {

    vector<int> preorder = {1, 2, 3, 4};
    vector<int> inorder  = {2, 1, 3, 4};

    Solution sol;
    TreeNode *root = sol.buildTree(preorder, inorder);

    // [1,2,3,null,null,null,4] -> preorder: 1 2 null null 3 null 4 null null
    printPreorder(root);
    cout << endl;

    return 0;
}
