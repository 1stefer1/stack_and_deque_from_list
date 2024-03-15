#include <iostream>
#include "List.h"
#include "Stack.h"
#include "Deque.h"
using namespace std;


int main() { 
    // Проверка стека
    cout << "Проверка стека:" << endl;
    Stack<int> stack;

    stack.push(1);
    stack.push(2);
    stack.push(3);

    cout << "Вывод стека: ";
    stack.printStack(); // Ожидаем: 3 2 1

    cout << "Высший элемент: " << stack.top() << endl; // Ожидаем: 3

    stack.pop();
    cout << "Высший элемент, после удаления: " << stack.top() << endl; // Ожидаем: 2

    stack.clear();
    cout << "Проверка пустоты стека: " << (stack.isEmpty() ? "Пуст" : "-1") << endl; // Ожидаем: Пуст

    // Проверка стека с типом данных double
    Stack<double> doubleStack;

    doubleStack.push(1.1);
    doubleStack.push(2.2);
    doubleStack.push(3.3);

    cout << "Double Stack: ";
    doubleStack.printStack(); // Ожидаем: 3.3 2.2 1.1
    cout << "Высший элемент: " << doubleStack.top() << endl; // Ожидаем: 3.3
    doubleStack.push(4.4);
    cout << "Высший элемент после добавления: " << doubleStack.top() << endl; // Ожидаем: 4.4
    doubleStack.clear();

    // Проверка дека
    cout << "=================\nПроверка дека:" << endl;
    Deque<int> deque;

    deque.pushFront(1);
    deque.pushBack(2);
    deque.pushFront(3);

    cout << "Вывод дека: ";
    deque.printDeque(); // Ожидаем: 3 1 2

    cout << "Первый элемент: " << deque.front() << endl; // Ожидаем: 3
    cout << "Последний элемент: " << deque.back() << endl; // Ожидаем: 2

    deque.popFront();
    cout << "После удаления с начала высший элемент: " << deque.front() << endl; // Ожидаем: 1

    deque.popBack();
    cout << "После удаления с конца высший элемент: " << deque.back() << endl; // Ожидаем: 1

    deque.clear();
    cout << "Проверка пустоты дека? " << (deque.isEmpty() ? "Пуст" : "-1") << endl; // Ожидаем: Пуст

    Deque<float> floatDeque;
    floatDeque.pushFront(1.1f);
    floatDeque.pushFront(2.2f);
    floatDeque.pushBack(3.3333f);

    cout << "\nFloat Deque: ";
    floatDeque.printDeque(); // Ожидаем: 2.2 1.1 3.3333
    cout << "=================\nПроверка задания с1(стек):" << endl;

    string test = "abc$cba"; // Пример строки для проверки

    if (stack.task_C1(test)) {
        cout << "Строка " << test <<" имеет вид w$w', где w' - реверс строки." << endl;
    }
    else {
        cout << "Строка "<< test <<" не имеет вид w$w', где w' - реверс строки." << endl;
    }

    cout << "=================\nПроверка задания с1(дек):" << endl;
    string testDeque = "abc$cba"; // Пример строки для проверки

    if (deque.task_C1(testDeque)) {
        cout << "Строка " << testDeque << " имеет вид w$w', где w' - реверс строки." << endl;
    }
    else {
        cout << "Строка " << testDeque << " не имеет вид w$w', где w' - реверс строки." << endl;
    }

    return 0;
}
