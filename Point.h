#pragma once
#include <iostream>

class Point
{
private:
	unsigned int x;
	unsigned int y;
	
public:
	/**
	* @brief Конструктор точки
	* @param x Координата X (по умолчанию 0)
	* @param y Координата Y (по умолчанию 0)
	*/
	Point(unsigned int x = 0, unsigned int y = 0);

	/**
	* @brief Получить координату X
	* @return Координата X
	*/
	unsigned int getX() const;

	/**
	* @brief Получить координату Y
	* @return Координата Y
	*/
	unsigned int getY() const;

	/**
	* @brief Оператор присваивания
	* @param other Точка, из которой копируются координаты
	* @return Ссылка на текущую точку
	*/
	Point& operator=(const Point& other);

	/**
	* @brief Оператор ввода точки
	* @param is Поток ввода
	* @param point Точка для ввода
	* @return Поток ввода
	* @throw std::invalid_argument если введены отрицательные координаты
	*/
	friend std::istream& operator>>(std::istream &is, Point& point);

	/**
	* @brief Оператор вывода точки
	* @param outP Поток вывода
	* @param point Точка для вывода
	* @return Поток вывода
	*/
	friend std::ostream& operator<<(std::ostream &outP, const Point& point);

	/**
	* @brief Оператор сложения точки с числом
	* @param value Число для сложения (может быть отрицательным)
	* @return Новая точка с координатами (x+value, y+value)
	*/
	Point operator+(int value) const;

	/**
	* @brief Оператор вычитания числа из точки
	* @param value Число для вычитания (должно быть ≤ текущих координат)
	* @return Новая точка с координатами (x-value, y-value)
	* @throw std::out_of_range если вычитание приведёт к отрицательному результату
	*/
	Point operator-(int value) const;

	/**
	* @brief Проверка коллинеарности трёх точек
	* @param p2 Вторая точка
	* @param p3 Третья точка
	* @return true если точки лежат на одной прямой, иначе false
	*/
	bool isCollinearWith(const Point& p2, const Point& p3) const;
};
/**
 * @brief Оператор сравнения точек на равенство
 * @param point1 Первая точка
 * @param point2 Вторая точка
 * @return true если координаты точек совпадают
 */
bool operator==(const Point& point1, const Point& point2);

/**
 * @brief Оператор сравнения точек на неравенство
 * @param point1 Первая точка
 * @param point2 Вторая точка
 * @return true если координаты точек различаются
 */
bool operator!=(const Point& point1, const Point& point2);
