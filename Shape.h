#pragma once
#include <iostream>
#include <vector>

class Shape {
public:
    /**
    * @brief Виртуальный метод отрисовки фигуры (выводит информацию о фигуре через toString())
    * @param os Выходной поток для отрисовки (по умолчанию std::cout)
    */
    virtual void draw(std::ostream& os = std::cout) const {
        os << "Drawing shape:\n" << toString();
    }

    /**
    * @brief Виртуальный метод получения строкового представления фигуры
    * @return Строковое описание фигуры
    */
    virtual std::string toString() const = 0;

    /**
    * @brief Виртуальный деструктор
    */
    virtual ~Shape() = default;

    /**
    * @brief Виртуальный метод чтения фигуры из потока
    * @param is Входной поток для чтения
    */
    virtual void readFromStream(std::istream& is) = 0;

    /**
    * @brief Виртуальный метод записи фигуры в поток
    * @param os Выходной поток для записи
    */
    virtual void writeToStream(std::ostream& os) {
        os << toString();
    }

};