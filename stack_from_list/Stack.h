#pragma once
#include "List.h"

template<typename T>
class Stack : private DoublyLinkedList<T> {
public:
    Stack() : DoublyLinkedList<T>() {}

    // Добавление элемента на вершину стека
    void push(const T& value) {
        DoublyLinkedList<T>::append(value);
    }

    // Удаление элемента с вершины стека
    void pop() {
        if (this->isEmpty()) {
            cout << "Stack is empty\n";
            return;
        }
        DoublyLinkedList<T>::remove(this->getSize() - 1);
    }

    // Получение верхнего элемента стека
    T& top() {
        if (this->isEmpty()) {
            cout << "Stack is empty\n";
            return this->head->data;
        }
        return this->tail->data;
    }

    // Проверка на пустоту
    bool isEmpty() {
        return DoublyLinkedList<T>::isEmpty();
    }

    // Просмотр и вывод
    void printStack() {
        DoublyLinkedList<T>::printBackward();
    }

    // Очистка стека
    void clear() {
        DoublyLinkedList<T>::clearFromEnd();
    }

    // Задание С1
    bool task_C1(const string& str) {
        Stack<char> stack; // Объявление стека

        bool flag = false; // Объявление флага

        // Запись "реверсной" строки в стек 
        for (auto i = str.cbegin(); i != str.cend(); ++i) {
            char ch = *i;
            if (ch == '$') {
                flag = true;
                continue;
            }
            if (flag) {
                stack.push(ch);
            }
        }

        for (auto i = str.cbegin(); i != str.cend(); ++i) {
            char ch = *i;
            if (ch == '$')
                break;
            if (stack.isEmpty() || stack.top() != ch)
                return false;
            stack.pop();
        }
        
        // Если символы строк совпали
        return stack.isEmpty();
    }

};
