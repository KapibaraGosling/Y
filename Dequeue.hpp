#include <iostream>
#include <stdexcept>
#include <utility>
#include <string>
#include <sstream>
#include <initializer_list>
#pragma once

template <typename T>
class Deque {
private:
    T* buffer;
    size_t capacity;
    size_t head;
    size_t tail;
    size_t current_size;

    void resize();

public:
    // Конструкторы/деструктор
    Deque();
    explicit Deque(size_t initial_capacity);
    Deque(std::initializer_list<T> init);
    Deque(const Deque& other);
    Deque(Deque&& other) noexcept;
    ~Deque();

    // Основные операции
    void push_front(const T& value);
    void push_back(const T& value);
    void pop_front();
    void pop_back();

    // Доступ к элементам
    const T& front() const;
    const T& back() const;
    const T& operator[](size_t index) const;

    // Информация
    size_t size() const;
    bool empty() const;

    // Операторы и функции
    Deque& operator=(const Deque& other);

    friend void swap(Deque<T>& a, Deque<T>& b) noexcept;
    
    friend std::istream& operator>>(std::istream& is, Deque& dq) {
        T value;
        while (is >> value) {
            dq.push_back(value);
        }
        return is;
    }

    friend std::ostream& operator<<(std::ostream& os, const Deque& dq) {
        os << "[";
        if (!dq.empty()) {
            size_t pos = dq.head;
            for (size_t i = 0; i < dq.current_size; ++i) {
                os << dq.buffer[pos];
                if (i != dq.current_size - 1) os << ", ";
                pos = (pos + 1) % dq.capacity;
            }
        }
        os << "]";
        return os;
    }
    //Реализацию перегрузки операторов компилятор видит только в заголовочном файле...
    std::string toString() const;
};

#include "Dequeue.ipp"