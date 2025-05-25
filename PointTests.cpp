#include <gtest/gtest.h>
#include "Point.h"
#include <sstream>

TEST(PointTest, DefaultConstruction) {
    Point p;
    EXPECT_EQ(p.getX(), 0);
    EXPECT_EQ(p.getY(), 0);
}

TEST(PointTest, ParameterizedConstruction) {
    Point p(10, 20);
    EXPECT_EQ(p.getX(), 10);
    EXPECT_EQ(p.getY(), 20);
}

TEST(PointTest, EqualityOperator) {
    Point p1(5, 10);
    Point p2(5, 10);
    Point p3(5, 15);

    EXPECT_TRUE(p1 == p2);
    EXPECT_FALSE(p1 == p3);
}

TEST(PointTest, InequalityOperator) {
    Point p1(1, 2);
    Point p2(1, 2);

    EXPECT_FALSE(p1 != p2);
}

TEST(PointTest, AssignmentOperator) {
    Point p1(10, 20);
    Point p2;
    p2 = p1;

    EXPECT_EQ(p2.getX(), 10);
    EXPECT_EQ(p2.getY(), 20);
}

TEST(PointTest, CollinearCheck) {
    Point p1(0, 0);
    Point p2(1, 1);
    Point p3(2, 2);  // Коллинеарны
    Point p4(0, 1);  // Не коллинеарны

    EXPECT_TRUE(p1.isCollinearWith(p2, p3));
    EXPECT_FALSE(p1.isCollinearWith(p2, p4));
}

TEST(PointTest, StreamInput) {
    Point p;
    std::istringstream iss("15 25");
    iss >> p;

    EXPECT_EQ(p.getX(), 15);
    EXPECT_EQ(p.getY(), 25);
}

TEST(PointTest, StreamInputNegative) {
    Point p;
    std::istringstream iss("-5 10");

    EXPECT_THROW(iss >> p, std::invalid_argument);
}

TEST(PointTest, StreamOutput) {
    Point p(7, 9);
    std::ostringstream oss;
    oss << p;

    EXPECT_TRUE(oss.str().find("(7; 9)") != std::string::npos);
}
