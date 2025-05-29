#pragma once

#include "Point.h"
#include "Shape.h"
#include <vector>
class Polygon : public Shape

{

private:
	
	std::vector<Point> points;
	static unsigned int screenWidth;
	static unsigned int screenHeight;
	/**
	* @brief Проверка точек многоугольника
	* @throw std::invalid_argument если количество точек < 3 или координаты выходят за границы экрана
	* @throw std::logic_error если есть совпадающие точки или три коллинеарные точки
	*/
	void validatePointsCheck() const;
public:
	/**
	* @brief Конструктор по умолчанию
	* @param width Ширина экрана (по умолчанию 1920)
	* @param height Высота экрана (по умолчанию 1080)
	*/
	Polygon(unsigned int width = 1920, unsigned int height = 1080);

	/**
	* @brief Конструктор из списка инициализации точек
	* @param points Список точек многоугольника
	* @param screen_width Ширина экрана для проверки границ
	* @param screen_height Высота экрана для проверки границ
	*/
	Polygon(std::initializer_list<Point> points,
		unsigned int screen_width,
		unsigned int screen_height);

	/**
	* @brief Конструктор из списка пар координат
	* @param coords Список пар координат точек
	* @param screen_width Ширина экрана для проверки границ
	* @param screen_height Высота экрана для проверки границ
	*/
	Polygon(const std::initializer_list<std::pair<int, int>>& coords,
		unsigned int screen_width, unsigned int screen_height);

	/**
	* @brief Конструктор копирования
	* @param other Другой объект Polygon для копирования
	*/
	Polygon(const Polygon& other);

	/**
	* @brief Конструктор перемещения
	* @param other Другой объект Polygon для перемещения
	*/
	Polygon(Polygon&& other) noexcept;

	/**
	* @brief Получить точку по порядковому номеру
	* @param sequence_number Номер точки (начиная с 0)
	* @return Объект Point
	* @throw std::out_of_range если номер точки выходит за границы
	*/
	Point getPoint(const int sequence_number) const;

	/**
	* @brief Получить ширину экрана
	* @return Текущая ширина экрана
	*/
	unsigned int getScreenWidth()const;

	/**
	* @brief Получить высоту экрана
	* @return Текущая высота экрана
	*/
	unsigned int getScreenHeight()const;


	/**
	* @brief Оператор присваивания (копирование)
	* @param other Присваеваемый объект Polygon
	* @return Ссылка на текущий объект
	*/
	Polygon& operator=(const Polygon& other);

	/**
	* @brief Оператор присваивания (перемещение)
	* @param other Присваеваемый объект Polygon
	* @return Ссылка на текущий объект
	*/
	Polygon& operator=(Polygon&& other) noexcept;
	~Polygon()=default;

	/**
	* @brief Получить строковое представление многоугольника
	* @return Строка вида "Polygon[(x1; y1), (x2; y2), ...]"
	*/
	std::string toString() const override;

	/**
	* @brief Чтение многоугольника из потока
	* @param is Входной поток для чтения
	*/
	void readFromStream(std::istream& is) override;
};