#pragma once
using namespace std;

template<typename T>
class DoublyLinkedList {
protected:
    struct Node {
        T data;
        Node* next;
        Node* prev;
        Node(const T& value) : data(value), next(nullptr), prev(nullptr) {}
    };

    Node* head;
    Node* tail;
    int size;

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr), size(0) {}

    // Конструктор копирования
    DoublyLinkedList(const DoublyLinkedList& other) {
        head = nullptr;
        tail = nullptr;
        size = 0;

        Node* temp = other.head;
        while (temp != nullptr) {
            append(temp->data);
            temp = temp->next;
        }
    }

    // Деструктор
    ~DoublyLinkedList() {
        clear();
    }

    // Методы добавления элементов
    void prepend(const T& value) {
        Node* newNode = new Node(value);
        if (isEmpty()) {
            head = newNode;
            tail = newNode;
        }
        else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        size++;
    }

    void append(const T& value) {
        Node* newNode = new Node(value);
        if (isEmpty()) {
            head = newNode;
            tail = newNode;
        }
        else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        size++;
    }

    void insert(const T& value, int pos) {
        if (pos < 0 || pos > size) {
            cout << "Invalid position\n";
            return;
        }
        if (pos == 0) {
            prepend(value);
        }
        else if (pos == size) {
            append(value);
        }
        else {
            Node* temp = head;
            for (int i = 0; i < pos - 1; ++i) {
                temp = temp->next;
            }
            Node* newNode = new Node(value);
            newNode->next = temp->next;
            newNode->prev = temp;
            temp->next->prev = newNode;
            temp->next = newNode;
            size++;
        }
    }

    // Метод удаления элементов
    void remove(int pos) {
        if (pos < 0 || pos >= size) {
            cout << "Invalid position\n";
            return;
        }
        if (pos == 0) {
            Node* temp = head;
            head = head->next;
            if (head != nullptr) {
                head->prev = nullptr;
            }
            else {
                tail = nullptr;
            }
            delete temp;
        }
        else if (pos == size - 1) {
            Node* temp = tail;
            tail = tail->prev;
            tail->next = nullptr;
            delete temp;
        }
        else {
            Node* temp = head;
            for (int i = 0; i < pos; ++i) {
                temp = temp->next;
            }
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            delete temp;
        }
        size--;
    }

    // Удаление с начала
    void clear() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
        tail = nullptr;
        size = 0;
    }

    // Удаление с конца
    void clearFromEnd() {
        while (tail != nullptr) {
            Node* temp = tail;
            tail = tail->prev;
            delete temp;
        }
        head = nullptr;
        size = 0;
    }

    // Просмотр и вывод
    void printForward() const {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    void printBackward() const {
        Node* temp = tail;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->prev;
        }
        cout << endl;
    }

    // Получение размера списка
    int getSize() const {
        return size;
    }

    // Проверка списка на пустоту
    bool isEmpty() const {
        return size == 0;
    }
};