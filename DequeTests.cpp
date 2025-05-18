#include "DequeTests.h"
using namespace std;
void test_constructors() {
    // Конструктор по умолчанию
    Deque<int> d1;
    assert(d1.empty());

    // Конструктор с capacity
    Deque<int> d2(5);
    assert(d2.empty());

    // Конструктор из списка
    Deque<int> d3 = { 1, 2, 3 };
    assert(d3.size() == 3);
    assert(d3.front() == 1);
    assert(d3.back() == 3);

    cout << "Constructor tests passed!\n";
}

void test_push_pop() {
    Deque<int> dq;

    // Push back
    dq.push_back(10);
    assert(dq.back() == 10);
    dq.push_back(20);
    assert(dq.back() == 20);

    // Push front
    dq.push_front(5);
    assert(dq.front() == 5);

    // Pop back
    dq.pop_back();
    assert(dq.back() == 10);

    // Pop front
    dq.pop_front();
    assert(dq.front() == 10);

    cout << "Push/pop tests passed!\n";
}

void test_inout_operators() {
    Deque<int> dq;
    stringstream ss;

    // Тест оператора >>
    ss << "10 20 30";
    ss >> dq;
    assert(dq.size() == 3);
    assert(dq.front() == 10);
    assert(dq.back() == 30);

    // Тест оператора <<
    ss.clear();
    ss.str("");
    ss << dq;
    assert(ss.str() == "[10, 20, 30]");

    cout << "Input/Output operators tests passed!\n";
}

void test_copy_move() {
    Deque<int> original = { 1, 2, 3 };

    // Копирование
    Deque<int> copy = original;
    assert(copy.size() == 3);
    assert(copy.front() == 1);

    // Перемещение
    Deque<int> moved = move(original);
    assert(moved.size() == 3);
    assert(original.empty());

    cout << "Copy/move tests passed!\n";
}

void test_edge_cases() {
    Deque<int> dq;

    // Попытка доступа к пустому деке
    try {
        dq.front();
        assert(false); // Не должно сюда попасть
    }
    catch (const out_of_range&) {}

    // Очистка
    dq.push_back(1);
    dq.pop_back();
    assert(dq.empty());

    cout << "Edge cases tests passed!\n";
}