#pragma once
#include "Ryangosling.h"
#include "₍^. .^₎.h"
#include <iostream>
#include <string>
#include <stdexcept>
#include <cmath>
using std::cout;
using std::cin;
/*
@brief Функция запрашивает ввод числа с клавиатуры и проверяет его корректность.
@return возвращает введенное пользователем число типа double.
*/
double getCoordinate();

/*
@brief Функция расчитывает радиус вписанной в треугольник окружности
@param triangle - объект класса Triangle - заданный треугольник.
@return возвращает результат типа double.
*/
double calculateRadiusOfInscribed(const Triangle& triangle);

/*
@brief Функция расчитывает радиус описанной около треугольника окружности
@param triangle - объект класса Triangle - заданный треугольник.
@return возвращает результат типа double.
*/
double calculateRadiusOfCircumscribed(const Triangle& triangle);