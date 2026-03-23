#include "hashtable.h"

HashTable::HashTable(int c)
{
    capacity = c;

    /// Aqui es donde se crea el arreglo de punteros
    ///  1 [*] -> |* | -> | |
    ///  2 [*] -> |* | -> | |
    ///  3 [*] -> |* | -> | |
    ///  4 [*] -> |* | -> | |
    ///  5 [*] -> |* | -> | |
    ///  6 [*] -> |* | -> | |
    ///  7 [*] -> |* | -> | |
    ///  8 [*] -> |* | -> | |
    table = new Node *[capacity];


    /// Se teamos todos los punteros como nulos
    for (int i = 0; i < capacity; ++i) {
        table[i] = nullptr;
    }

}

HashTable::~HashTable()
{

    for (int i = 0; i < capacity; ++i) {
        Node *current = table[i];
        while(current != nullptr){
            Node* temp = current;
            current = current->next;
            delete temp;
        }
    }

    delete table;
}


void HashTable::insert(int key, const string &value)
{

    int index = hash(key);

    Node *current = table[index];

    while(current != nullptr){
        if(current->key == key){
            current->value = value;
            return;
        }

        current = current->next;
    }



    Node *newNode  = new Node(key, value);
    /// table[index] --> A --> B --> C --> nullptr
    /// newNode --> A --> B --> C --> nullptr
    newNode->next = table[index];


    // table[index] --> NEW --> A --> B --> C --> nullptr
    table[index] = newNode;

}

bool HashTable::contains(int key) const
{

    int index = hash(key);

    Node *current = table[index];

    while(current != nullptr){
        if(current->key == key) return true;

        current =  current->next;
    }

    return false;
}

string HashTable::get(int key) const
{

    int index(hash(key));

    Node *current = table[index];

    while(current != nullptr){
        if(current->key == key) return current->value;

        current = current->next;
    }

    return "Doesn't exist";

}

void HashTable::print() const
{
    for (int i = 0; i < capacity; ++i) {
        cout<< i << ":";

        Node *current = table[i];

        while(current != nullptr){
            cout << "[ " << current->key << ", " << current->value << " ] -->";
            current = current->next;
        }

        cout << "NULL_PTR" <<endl;

    }

}
