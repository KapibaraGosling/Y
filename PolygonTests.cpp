#include <gtest/gtest.h>
#include "Polygon.h"
#include <sstream>

class PolygonTest : public ::testing::Test {
protected:
    void SetUp() override {
        testPoints = { {0, 0}, {0, 10}, {10, 10}, {10, 0} };
        testCoords = { {0, 0}, {0, 5}, {5, 5}, {5, 0} };
        screenWidth = 1920;
        screenHeight = 1080;
    }

    std::vector<Point> testPoints;
    std::vector<std::pair<int, int>> testCoords;
    unsigned int screenWidth;
    unsigned int screenHeight;
};

TEST_F(PolygonTest, DefaultConstructor) {
    Polygon p(screenWidth, screenHeight);
    EXPECT_EQ(p.getScreenWidth(), screenWidth);
    EXPECT_EQ(p.getScreenHeight(), screenHeight);
    EXPECT_TRUE(p.toString().find("Polygon[]") != std::string::npos);
}

TEST_F(PolygonTest, PointsListConstructor) {
    Polygon p(testPoints, screenWidth, screenHeight);
    EXPECT_EQ(p.getPoint(0), Point(0, 0));
    EXPECT_EQ(p.getPoint(1), Point(0, 10));
}

TEST_F(PolygonTest, CoordsListConstructor) {
    Polygon p(testCoords, screenWidth, screenHeight);
    EXPECT_EQ(p.getPoint(0), Point(0, 0));
    EXPECT_EQ(p.getPoint(1), Point(0, 5));
}

TEST_F(PolygonTest, CopyConstructor) {
    Polygon p1(testPoints, screenWidth, screenHeight);
    Polygon p2(p1);

    EXPECT_EQ(p2.getPoint(0), Point(0, 0));
    EXPECT_EQ(p2.getScreenWidth(), screenWidth);
}

TEST_F(PolygonTest, MoveConstructor) {
    Polygon p1(testPoints, screenWidth, screenHeight);
    Polygon p2(std::move(p1));

    EXPECT_EQ(p2.getPoint(0), Point(0, 0));
    EXPECT_TRUE(p1.toString().find("[]") != std::string::npos);  // Проверяем что p1 пуст
}

TEST_F(PolygonTest, AssignmentOperator) {
    Polygon p1(testPoints, screenWidth, screenHeight);
    Polygon p2(screenWidth, screenHeight);
    p2 = p1;

    EXPECT_EQ(p2.getPoint(0), Point(0, 0));
}

TEST_F(PolygonTest, ValidationChecks) {
    // Недостаточно точек
    EXPECT_THROW(Polygon({ {0,0}, {1,1} }, screenWidth, screenHeight), std::invalid_argument);

    // Совпадающие точки
    EXPECT_THROW(Polygon({ {0,0}, {0,0}, {1,1} }, screenWidth, screenHeight), std::logic_error);

    // Коллинеарные точки
    EXPECT_THROW(Polygon({ {0,0}, {1,1}, {2,2}, {3,3} }, screenWidth, screenHeight), std::logic_error);

    // Точки за границами экрана
    EXPECT_THROW(Polygon({ {0,0}, {0,2000}, {2000,0} }, screenWidth, screenHeight), std::out_of_range);
}

TEST_F(PolygonTest, DrawMethod) {
    Polygon p(testPoints, screenWidth, screenHeight);
    testing::internal::CaptureStdout();
    p.draw();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_TRUE(output.find("Drawing polygon") != std::string::npos);
    EXPECT_TRUE(output.find("(0; 0)") != std::string::npos);
}