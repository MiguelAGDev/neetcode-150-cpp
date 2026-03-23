#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <iostream>
#include <string>
using namespace std;

class HashTable
{

    // ESTRUCTURA DE NODOS
    // Realiza una estructura de arreglo de punteros
    ///
    ///  1 [ ] -> | | -> | |
    ///  2 [ ] -> | | -> | |
    ///  3 [ ] -> | | -> | |
    ///  4 [ ] -> | | -> | |
    ///  5 [ ] -> | | -> | |
    ///  6 [ ] -> | | -> | |
    ///  7 [ ] -> | | -> | |
    ///  8 [ ] -> | | -> | |

    struct Node{

        int key;
        string value;
        Node *next;


        Node(int k, const string &v)
            : key(k),value(v), next(nullptr){};

    };

    /// Puntero de puntero, aqui todavia no se asigna como arreglo,
    /// solo como puntero de un puntero
    Node **table;

    ///
    /// \brief capacity
    /// Capacidad del arreglo hash
    int capacity;

    inline int hash(int key) const {
        return key % capacity;
    };


public:
    //Crea la tabla con la capacidad dadda
    HashTable(int c = 7);

    // Libera toda la memoria reservada
    ~HashTable();

    // Inserta una clave
    void insert(int key, const string &value);

    // Verifica si la clave existe
    bool contains(int key) const;

    // Obtiene el valor asociado con la clave
    string get(int key) const;

    // Imprime la tabla hash
    void print() const;






};

#endif // HASHTABLE_H
