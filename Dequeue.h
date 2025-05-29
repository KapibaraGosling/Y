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
    /**
     * @brief Конструктор по умолчанию. Создает пустой дек.
     */
    Deque() : buffer(nullptr), current_size(0) {}

    /**
    * @brief Конструктор из списка инициализации
    * @param init Список инициализации элементов дека
    */
    Deque(std::initializer_list<T> init) :
        buffer(new T[init.size()]),
        current_size(init.size()) {
        std::copy(init.begin(), init.end(), buffer);
    }

    /**
     * @brief Конструктор копирования
     * @param other Дек для копирования
     */
    Deque(const Deque& other) :
        buffer(new T[other.current_size]),
        current_size(other.current_size) {
        std::copy(other.buffer, other.buffer + other.current_size, buffer);
    }

    /**
     * @brief Конструктор перемещения
     * @param other Дек для перемещения
     */
    Deque(Deque&& other) noexcept : buffer(nullptr), current_size(0)
    {
        swap(*this, other);
    }

    /**
     * @brief Деструктор. Освобождает динамическую память.
     */
    ~Deque() {
        delete[] buffer;
    }

    /**
     * @brief Добавляет элемент в начало дека
     * @param value Элемент для добавления
     */
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

    /**
     * @brief Добавляет элемент в конец дека
     * @param value Элемент для добавления
     */
    void push_back(const T& value) {
        T* new_buffer = new T[current_size + 1];

        for (size_t i = 0; i < current_size; ++i) {
            new_buffer[i] = buffer[i];
        }

        new_buffer[current_size] = value;

        delete[] buffer;
        buffer = new_buffer;
        current_size++;
    }

    /**
     * @brief Удаляет элемент из начала дека
     * @throw std::out_of_range Если дек пуст
     */
    void pop_front() {
        if (empty()) throw std::out_of_range("Deque is empty");

        if (current_size == 1) {
            delete[] buffer;
            buffer = nullptr;
            current_size = 0;
        }
        else {
            T* new_buffer = new T[current_size - 1];

            for (size_t i = 1; i < current_size; ++i) {
                new_buffer[i - 1] = buffer[i];
            }

            delete[] buffer;
            buffer = new_buffer;
            current_size--;
        }
    }

    /**
     * @brief Удаляет элемент из конца дека
     * @throw std::out_of_range Если дек пуст
     */
    void pop_back() {
        if (empty()) throw std::out_of_range("Deque is empty");

        if (current_size == 1) {
            delete[] buffer;
            buffer = nullptr;
            current_size = 0;
        }
        else {
            T* new_buffer = new T[current_size - 1];

            for (size_t i = 0; i < current_size - 1; ++i) {
                new_buffer[i] = buffer[i];
            }

            delete[] buffer;
            buffer = new_buffer;
            current_size--;
        }
    }

    /**
     * @brief Возвращает ссылку на первый элемент дека
     * @return Константная ссылка на первый элемент
     * @throw std::out_of_range Если дек пуст
     */
    const T& front() const {
        if (empty()) throw std::out_of_range("Deque is empty");
        return buffer[0];
    }

    /**
     * @brief Возвращает ссылку на последний элемент дека
     * @return Константная ссылка на последний элемент
     * @throw std::out_of_range Если дек пуст
     */
    const T& back() const {
        if (empty()) throw std::out_of_range("Deque is empty");
        return buffer[current_size - 1];
    }

    /**
     * @brief Оператор доступа к элементу по индексу
     * @param index Индекс элемента
     * @return Константная ссылка на элемент по индексу
     * @throw std::out_of_range Если индекс выходит за границы
     */
    const T& operator[](size_t index) const {
        if (index >= current_size) throw std::out_of_range("Index out of range");
        return buffer[index];
    }

    /**
     * @brief Возвращает количество элементов в деке
     * @return Количество элементов
     */
    size_t size() const {
        return current_size;
    }

    /**
     * @brief Проверяет, пуст ли дек
     * @return true если дек пуст
     */
    bool empty() const {
        return current_size == 0;
    }

    /**
     * @brief Оператор присваивания
     * @param other Дек для копирования
     * @return Ссылка на текущий дек
     */
    Deque& operator=(const Deque& other) {
        if (this != &other) {
            Deque temp(other);
            swap(*this, temp);
        }
        return *this;
    }
    
    /**
     * @brief Обменивает содержимое двух деков
     * @param a Первый дек для обмена
     * @param b Второй дек для обмена
     */
    friend void swap(Deque<T>& a, Deque<T>& b) noexcept {
        std::swap(a.buffer, b.buffer);
        std::swap(a.current_size, b.current_size);
    }

    /**
     * @brief Оператор ввода
     * @param is Поток ввода
     * @param dq Дек для заполнения
     * @return Поток ввода
     */
    friend std::istream& operator>>(std::istream& is, Deque& dq) {
        T value;
        while (is >> value) {
            dq.push_back(value);
        }
        return is;
    }

    /**
     * @brief Оператор вывода элементов дека
     * @param os Поток вывода
     * @param dq Дек для вывода
     * @return Поток вывода
     */
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
    
    /**
    * @brief Преобразует дек в строку
    * @return Строковое представление дека
    */
    std::string toString() const {
        std::ostringstream oss;
        oss << *this;
        return oss.str();
    }
};
