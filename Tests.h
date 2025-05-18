#pragma once

#include "Polygon.h"
#include "Point.h"
#include <iostream>

// Point class tests
void test_point_constructors_and_getters();
void test_point_operators();
void test_point_collinearity();

// Polygon class tests
void test_polygon_constructors();
void test_polygon_validation();
void test_polygon_copy_move();
void test_polygon_edge_cases();

// Main test runner
void run_all_tests();