#include <iostream>
#include "hashtable.h"


using namespace std;

int main()
{
    HashTable tablaHash(5);

    tablaHash.insert(13,"Miguel");
    tablaHash.insert(15,"Gera");
    tablaHash.insert(20,"Rodrigo");
    tablaHash.insert(30,"Maria");
    tablaHash.insert(11,"Paola");
    tablaHash.insert(7,"Azu");
    tablaHash.insert(4,"Luis");

    cout << tablaHash.contains(15) << endl; // 1 (true)
    cout << tablaHash.contains(99) << endl; // 0 (false)

    cout << tablaHash.get(15) << endl; // D


    tablaHash.print();


}
