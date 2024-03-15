#pragma once
#include "List.h"

template<typename T>
class Deque : protected DoublyLinkedList<T> {
public:
    Deque() : DoublyLinkedList<T>() {}

    // Добавление элемента в начало дека
    void pushFront(const T& value) {
        DoublyLinkedList<T>::prepend(value);
    }

    // Добавление элемента в конец дека
    void pushBack(const T& value) {
        DoublyLinkedList<T>::append(value);
    }

    // Удаление элемента с начала дека
    void popFront() {
        if (this->isEmpty()) {
            cout << "Deque is empty\n";
            return;
        }
        DoublyLinkedList<T>::remove(0);
    }

    // Удаление элемента с конца дека
    void popBack() {
        if (this->isEmpty()) {
            cout << "Deque is empty\n";
            return;
        }
        DoublyLinkedList<T>::remove(this->getSize() - 1);
    }

    // Получение первого элемента дека
    T& front() {
        if (this->isEmpty()) {
            cout << "Deque is empty\n";
            return this->head->data; // Возвращаем ссылку на временный объект
        }
        return this->head->data;
    }

    // Получение последнего элемента дека
    T& back() {
        if (this->isEmpty()) {
            cout << "Deque is empty\n";
            return this->head->data; // Возвращаем ссылку на временный объект
        }
        return this->tail->data;
    }

    // Проверка на пустоту
    bool isEmpty() {
        return DoublyLinkedList<T>::isEmpty();
    }

    // Просмотр и вывод дека
    void printDeque() {
        DoublyLinkedList<T>::printForward();
    }

    // Очистка дека
    void clear() {
        DoublyLinkedList<T>::clear();
    }

    bool task_C1(const string& expression) {
        Deque<char> deque;

        // Полностью переписываем строку в дек
        for (char ch : expression) {
            deque.pushBack(ch);
        }

        // Пока дек не пуст и пока символы в начале и конце дека совпадают
        while (!deque.isEmpty() && deque.front() == deque.back()) {
            deque.popFront();
            if (!deque.isEmpty()) // Проверка на пустоту после каждого удаления
                deque.popBack();
        }

        // Проверяем, что после удаления символов дек остался пустым
        return deque.isEmpty();
    }



};
