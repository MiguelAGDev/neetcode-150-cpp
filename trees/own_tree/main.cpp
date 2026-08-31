#include <iostream>
#include "tree.h"
using namespace std;

int main() {
    tree t;

    // inserciones iniciales
    t.insert(45);
    t.insert(3);
    t.insert(15);
    t.insert(32);
    t.insert(44);
    t.insert(90);
    t.insert(63);


    t.printAsArray();
    return 0;
}
