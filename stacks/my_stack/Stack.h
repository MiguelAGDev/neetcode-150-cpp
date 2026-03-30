#ifndef STACK_H
#define STACK_H

#include <vector>
#include <stdexcept>
#include <utility> // std::move

/**
 * Clase template Stack<T>
 * Implementación de pila usando std::vector internamente.
 */

template <typename T>
class Stack {
private:
    std::vector<T> data;

public:
    Stack() = default; // vector ya se inicializa vacío

    // Inserta un elemento (lvalue)
    void push(const T& value) {
        data.push_back(value);
    }

    // Inserta un elemento (rvalue)
    void push(T&& value) {
        data.push_back(std::move(value));
    }

    // Elimina el elemento superior
    void pop() {
        if (isEmpty())
            throw std::runtime_error("Stack underflow");
        data.pop_back();
    }

    // Devuelve referencia al elemento superior
    T& peek() {
        if (isEmpty())
            throw std::runtime_error("Stack empty");
        return data.back();
    }

    // Comprueba si la pila está vacía
    bool isEmpty() const {
        return data.empty();
    }

    // Devuelve el tamaño de la pila
    int size() const {
        return static_cast<int>(data.size());
    }
};

#endif // STACK_H
