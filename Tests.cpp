#include <cassert>
#include <vector>
#include "Tests.h"

using namespace std;

void test_point_constructors_and_getters() {

    Point p1;
    assert(p1.getX() == 0 && p1.getY() == 0);

    Point p2(5, 10);
    assert(p2.getX() == 5 && p2.getY() == 10);

    cout << "Point constructors and getters tests passed!\n\n";
}

void test_point_operators() {

    Point p1(5, 10);
    Point p2 = p1;
    assert(p2.getX() == 5 && p2.getY() == 10);

    Point p3 = p1 + p2;
    assert(p3.getX() == 10 && p3.getY() == 20);

    Point p4 = p3 - p2;
    assert(p4.getX() == 5 && p4.getY() == 10);

    assert(p1 == p2);
    assert(!(p1 == Point()));
    assert(p1 != Point());

    cout << "Point operators tests passed!\n\n";
}

void test_point_collinearity() {

    Point p1(0, 0), p2(1, 1), p3(2, 2);
    assert(p1.isCollinearWith(p2, p3));

    Point p4(0, 1);
    assert(!p1.isCollinearWith(p2, p4));

    Point p5(1, 0), p6(2, 0), p7(3, 0);
    assert(p5.isCollinearWith(p6, p7));

    cout << "Point collinearity tests passed!\n\n";
}

void test_polygon_constructors() {

    Polygon p0;
    try {
        p0.getPoint(0);
        assert(false);
    }
    catch (const std::out_of_range&) {}

    Point points[] = { {0, 0}, {1, 0}, {1, 1}, {0, 1} };
    Polygon p1(points, 4);
    assert(p1.getPoint(0) == Point(0, 0));
    assert(p1.getPoint(3) == Point(0, 1));

    int x[] = { 0, 1, 1, 0 };
    int y[] = { 0, 0, 1, 1 };
    Polygon p2(x, y, 4);
    assert(p2.getPoint(1) == Point(1, 0));

    cout << "Polygon constructors tests passed!\n\n";
}

void test_polygon_validation() {

    Point badPoints1[] = { {0, 0}, {0, 0} };
    try {
        Polygon p3(badPoints1, 2);
        assert(false); 
    }
    catch (const std::logic_error& e) {
        assert(std::string(e.what()) == "The points match");
    }

    Point badPoints2[] = { {0, 0}, {1, 1}, {2, 2} };
    try {
        Polygon p4(badPoints2, 3);
        assert(false); 
    }
    catch (const std::logic_error& e) {
        assert(std::string(e.what()) == "Three points lie on the same straight line");
    }

    try {
        Polygon p5(nullptr, 1);
        assert(false);
    }
    catch (const std::invalid_argument& e) {
        assert(std::string(e.what()) == "Null pointer passed");
    }

    cout << "Polygon validation tests passed!\n\n";
}

void test_polygon_copy_move() {

    Point points[] = { {0, 0}, {1, 0}, {1, 1} };
    Polygon original(points, 3);

    Polygon copy = original;
    assert(copy.getPoint(1) == Point(1, 0));

    Polygon moved = std::move(original);
    assert(moved.getPoint(2) == Point(1, 1));
    try {
        original.getPoint(0);
        assert(false);
    }
    catch (const std::out_of_range&) {}

    cout << "Polygon copy/move tests passed!\n\n";
}

void test_polygon_edge_cases() {

    Point trianglePoints[] = { {0, 0}, {1, 0}, {0, 1} };
    Polygon triangle(trianglePoints, 3);
    assert(triangle.getPoint(2) == Point(0, 1));

    Polygon empty;
    try {
        empty.getPoint(0);
        assert(false); 
    }
    catch (const std::out_of_range&) {}

    cout << "Polygon edge cases tests passed!\n\n";
}

void run_all_tests() {
    test_point_constructors_and_getters();
    test_point_operators();
    test_point_collinearity();

    test_polygon_constructors();
    test_polygon_validation();
    test_polygon_copy_move();
    test_polygon_edge_cases();

    cout << "All tests passed successfully!\n";
}

