/*
Serialize And Deserialize Binary Tree - Hard

Implement an algorithm to serialize and deserialize a binary tree.
Serialization is the process of converting an in-memory structure into a sequence of bits so that it can be stored or sent across a network to be reconstructed later in another computer environment.
You just need to ensure that a binary tree can be serialized to a string and this string can be deserialized to the original tree structure. There is no additional restriction on how your serialization/deserialization algorithm should work.
Note: The input/output format in the examples is the same as how NeetCode serializes a binary tree. You do not necessarily need to follow this format.

Example 1:
Input: root = [1,2,3,null,null,4,5]
Output: [1,2,3,null,null,4,5]

Example 2:
Input: root = []
Output: []

Constraints:
0 <= The number of nodes in the tree <= 10,000.
-1000 <= Node.val <= 1000

*/
#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <sstream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {

        if (!root)
            return "null";

        string data;
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {

            TreeNode* cur = q.front();
            q.pop();

            if (cur) {

                data += to_string(cur->val);
                data += ",";

                // Siempre agregamos ambos hijos.
                q.push(cur->left);
                q.push(cur->right);

            } else {

                data += "null,";
            }
        }

        data.pop_back(); // quitar la última coma

        return data;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {

        if (data == "null")
            return nullptr;

        vector<string> vals;
        string token;
        stringstream ss(data);

        while (getline(ss, token, ',')) {
            vals.push_back(token);
        }

        TreeNode* root = new TreeNode(stoi(vals[0]));

        queue<TreeNode*> q;
        q.push(root);

        int i = 1;

        while (!q.empty()) {

            TreeNode* cur = q.front();
            q.pop();

            // hijo izquierdo
            if (vals[i] != "null") {

                cur->left = new TreeNode(stoi(vals[i]));
                q.push(cur->left);

            }
            i++;

            // hijo derecho
            if (i < vals.size() && vals[i] != "null") {

                cur->right = new TreeNode(stoi(vals[i]));
                q.push(cur->right);

            }
            i++;
        }

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

    // [1,2,3,null,null,4,5]
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(5);

    Codec ser, deser;

    string data = ser.serialize(root);
    cout << "Serialized: " << data << endl;

    TreeNode *res = deser.deserialize(data);

    // [1,2,3,null,null,4,5] -> preorder: 1 2 null null 3 4 null null 5 null null
    cout << "Deserialized preorder: ";
    printPreorder(res);
    cout << endl;

    return 0;
}
