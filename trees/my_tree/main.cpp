
#include "my_tree.h"
#include <iostream>
using namespace std;

int main() {
    BST tree;

    int sum = 0;
    for(int val : {10, 12, 22, 6, 1 , 7 ,9}){
        tree.insert(val);
        sum += val;
    }

    cout << "Level order:\n";         tree.levelOrder();


    cout <<"Minimun In Tree: "<< to_string( tree.findMin()) << endl;
    cout <<"Maximun In Tree: "<< to_string( tree.findMax()) << endl;
    cout <<"Total Nodes: "<<to_string(tree.countNodes())<<endl;
    cout <<"Total Leaves: "<<to_string(tree.countLeaves())<<endl;
    cout <<"Sumatory of All: "<<to_string(tree.sumNodes())<< " == "<< to_string(sum)<<endl;
    cout <<"Is In A Range Of [L ,R]: "<<tree.existInRange(1000,3000)<<endl;
}










































// ─────────────────────────────────────────
//  MAIN — quick smoke test
// ─────────────────────────────────────────
/* int main() {
    BST tree;

    for (int v : {5, 3, 7, 1, 4, 6, 8})
        tree.insert(v);

    //        5
    //       / \
    //      3   7
    //     / \ / \
    //    1  4 6  8

    cout << "Inorder    (sorted): "; tree.inorder();
    cout << "Preorder            : "; tree.preorder();
    cout << "Postorder           : "; tree.postorder();
    // cout << "Iterative inorder   : "; tree.iterativeInorder();
    cout << "Height              : " << tree.height() << "\n\n";

    cout << "Level order:\n";         tree.levelOrder();

    cout << "\nSearch 4: " << (tree.search(4) ? "found" : "not found") << "\n";
    cout << "Search 9: " << (tree.search(9) ? "found" : "not found") << "\n";

    tree.remove(3);
    cout << "\nAfter removing 3:\n";
    cout << "Inorder: "; tree.inorder();

    return 0;
}
*/
