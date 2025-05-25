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
    size_t current_size;


public:
    // Конструкторы/деструктор
    Deque() : buffer(nullptr), current_size(0) {}

    Deque(std::initializer_list<T> init) :
        buffer(new T[init.size()]),
        current_size(init.size()) {
        std::copy(init.begin(), init.end(), buffer);
    }
    Deque(const Deque& other) :
        buffer(new T[other.current_size]),
        current_size(other.current_size) {
        std::copy(other.buffer, other.buffer + other.current_size, buffer);
    }
    Deque(Deque&& other) noexcept : buffer(nullptr), current_size(0)
    {
        swap(*this, other);
    }
    ~Deque() {
        delete[] buffer;
    }

    // Основные операции
    void push_front(const T& value) {
        T* new_buffer = new T[current_size + 1];

        new_buffer[0] = value;

        for (size_t i = 0; i < current_size; ++i) {
            new_buffer[i + 1] = buffer[i];
        }

        delete[] buffer;
        buffer = new_buffer;
        current_size++;
    }
    void push_back(const T& value) {
        T* new_buffer = new T[current_size + 1];

        // Копируем старые элементы
        for (size_t i = 0; i < current_size; ++i) {
            new_buffer[i] = buffer[i];
        }

        // Добавляем новый элемент в конец
        new_buffer[current_size] = value;

        delete[] buffer;
        buffer = new_buffer;
        current_size++;
    }
    void pop_front() {
        if (empty()) throw std::out_of_range("Deque is empty");

        if (current_size == 1) {
            delete[] buffer;
            buffer = nullptr;
            current_size = 0;
        }
        else {
            T* new_buffer = new T[current_size - 1];

            // Копируем элементы, начиная со второго
            for (size_t i = 1; i < current_size; ++i) {
                new_buffer[i - 1] = buffer[i];
            }

            delete[] buffer;
            buffer = new_buffer;
            current_size--;
        }
    }


    void pop_back() {
        if (empty()) throw std::out_of_range("Deque is empty");

        if (current_size == 1) {
            delete[] buffer;
            buffer = nullptr;
            current_size = 0;
        }
        else {
            T* new_buffer = new T[current_size - 1];

            // Копируем все элементы кроме последнего
            for (size_t i = 0; i < current_size - 1; ++i) {
                new_buffer[i] = buffer[i];
            }

            delete[] buffer;
            buffer = new_buffer;
            current_size--;
        }
    }
    // Доступ к элементам
    const T& front() const {
        if (empty()) throw std::out_of_range("Deque is empty");
        return buffer[0];
    }
    const T& back() const {
        if (empty()) throw std::out_of_range("Deque is empty");
        return buffer[current_size - 1];
    }
    const T& operator[](size_t index) const {
        if (index >= current_size) throw std::out_of_range("Index out of range");
        return buffer[index];
    }
    // Информация
    size_t size() const {
        return current_size;
    }
    bool empty() const {
        return current_size == 0;
    }

    // Операторы и функции
    
    Deque& operator=(const Deque& other) {
        if (this != &other) {
            Deque temp(other);
            swap(*this, temp);
        }
        return *this;
    }
    
    friend void swap(Deque<T>& a, Deque<T>& b) noexcept {
        std::swap(a.buffer, b.buffer);
        std::swap(a.current_size, b.current_size);
    }
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
            for (size_t i = 0; i < dq.current_size; ++i) {
                os << dq.buffer[i];
                if (i != dq.current_size - 1) os << ", ";
            }
        }
        os << "]";
        return os;
    }
    
    std::string toString() const {
        std::ostringstream oss;
        oss << *this;
        return oss.str();
    }
};
