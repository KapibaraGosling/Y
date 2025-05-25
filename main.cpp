#include <iostream>
#include "../DequeLibrary/Dequeue.h"
using namespace std;
int main() {
    
    



    setlocale(LC_ALL, "rus");
    Deque<int> dq1, dq2 = { 10, 20, 30 };

    dq1.push_back(1);
    dq1.push_front(0);
    dq1.push_back(2);

    cout << "dq1: " << dq1 << "\n";

    cout << "Первый элемент: " << dq1.front() << "\n";
    cout << "Последний элемент: " << dq1.back() << "\n";

    dq1.pop_front();
    dq1.pop_back();
    cout << "После удаления: " << dq1 << "\n";

    Deque<int> dq4 = dq2; // Копирование 
    Deque<int> dq5 = move(dq2); // Перемещение (оставит dqw пустым)

    cout << "Размер dq4: " << dq4.size() << "\n";
    cout << "Пуст ли dq5? " << (dq5.empty() ? "Да" : "Нет") << "\n";

    cout << "Введите элементы дека: ";
    Deque<int> dq6;
    cin >> dq6;
    cout << "Вы ввели: " << dq6 << "\n";


    // Проверка на исключения
    try {
        cout << dq6.front(); // Попытка доступа к пустому деку
    }
    catch (const std::out_of_range& e) {
        cerr << "Ошибка: " << e.what() << "\n";
    }

    return 0;
}
