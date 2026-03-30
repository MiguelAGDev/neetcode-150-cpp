#include <iostream>
#include "Stack.h"  // Incluimos nuestra clase Stack

using namespace std;

int main() {
    // Creamos una pila de enteros
    Stack<int> s;

    cout << "Pushing 10, 20, 30 into stack..." << endl;
    s.push(10);
    s.push(20);
    s.push(30);

    cout << "Current stack size: " << s.size() << endl;

    cout << "Top element (peek): " << s.peek() << endl;

    cout << "Popping top element..." << endl;
    s.pop();

    cout << "Top element after pop: " << s.peek() << endl;
    cout << "Stack size now: " << s.size() << endl;

    // Vaciar la pila
    while (!s.isEmpty()) {
        cout << "Popping: " << s.peek() << endl;
        s.pop();
    }

    cout << "Stack empty? " << (s.isEmpty() ? "Yes" : "No") << endl;

    return 0;
}
