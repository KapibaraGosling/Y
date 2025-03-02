#pragma once
#include "Polygon.h"
#include "Point.h"
#include <iostream>
#include <string>
#include <stdexcept>
#include <cmath>
using std::cout;
using std::cin;
/*
@brief Функция запрашивает ввод числа с клавиатуры и проверяет его корректность.
@return возвращает введенное пользователем число типа int.
*/
int inputInt(void);

/*
@brief Функция проверки того, лежат ли 3 точки на одной прямой.
@param p1 - первая точка
@param p2 - вторая точка
@param p3 - третья точка
@return возвращает результат проверки.
*/
bool OnSameLine(const Point& p1, const Point& p2, const Point& p3);