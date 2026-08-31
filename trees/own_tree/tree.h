#ifndef TREE_H
#define TREE_H
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Node{

    int val;
    Node *left;
    Node *right;

    Node(): val(0), left(nullptr), right(nullptr){}
    Node(int value): val(value), left(nullptr), right(nullptr){}

};

class tree
{
private:

    Node *insert(Node* node, int value){

        if(!node) return new Node(value);

        if(value < node->val){
            node->left = insert(node->left, value);
        }
        else if(value > node->val){
            node ->right = insert(node->right, value);
        }

        return node;

    }

    bool count(Node* node, int value){

        if(!node) return false;

        if(value < node->val)
            return count(node->left, value);
        else if(value > node->val)
            return count(node->right, value);

        return true;

    }

    //①②③④⑤⑥⑦⑧⑨
    void erase(Node *&node, int value){

        if(!node) return;


        if(value < node->val)
            erase(node->left, value);
        else if(value > node->val)
            erase(node->right, value);
        else{

            /* AQUI EXISTEN TRES CASOS ESPACIFICOS

            1. QUE EL NODO NO TENGA HIJOS
            2. QUE TENGA UN SOLO HIJO
            3. QUE TENGA DOS HIJOS
        */

            Node* left = node->left;
            Node* right = node->right;

            // 1. Sin hijos
            if(!left && !right){
                delete node;
                return;
            }

            // 2. Un hijo
            if(!right){

                Node *temp = node;
                node = left;
                delete temp;
                return;
            }

            if(!left){
                Node *temp = node;
                node = right;
                delete temp;
                return;
            }

            // 3. POR CASO POSIBLE
            // TIENE DOS HIJOS

            if(left && right){

                Node *succ = right;

                // BUSCA AL MAS PEQUENHO DE LOS MAYORES
                // PARA TENER ELV ALOR MAS CERNCANO POSIBLE
                // O PUDIERA BUSCAR EL MAS GRANDE DE LOS MENORES
                while(succ->left) succ = succ->left;



                node->val = succ->val;

                erase(right, succ->val);
                return;
        }


        }

    }

    Node* root;

public:
    tree(): root(nullptr){};

    void insert(int value) {
        root = insert(root, value);
    }

    bool count(int value) {
        return count(root, value);
    }

    void erase(int value) {
        erase(root, value);
    }

    void printAsArray() {
        if(!root) {
            std::cout << "[]" << std::endl;
            return;
        }

        std::queue<Node*> q;
        q.push(root);
        std::vector<std::string> arr;

        while(!q.empty()) {
            Node* current = q.front();
            q.pop();

            if(current) {
                arr.push_back(std::to_string(current->val));
                q.push(current->left);
                q.push(current->right);
            } else {
                arr.push_back("null");
            }
        }

        // Elimina nulls sobrantes al final
        while(!arr.empty() && arr.back() == "null") {
            arr.pop_back();
        }

        std::cout << "[ ";
        for(size_t i = 0; i < arr.size(); i++) {
            std::cout << arr[i];
            if(i < arr.size() - 1) std::cout << ", ";
        }
        std::cout << " ]" << std::endl;
    }


};

#endif // TREE_H
