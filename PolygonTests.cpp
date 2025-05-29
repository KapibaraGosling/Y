#include <gtest/gtest.h>
#include "../GeometryLibrary/Polygon.h"
#include "../GeometryLibrary/Point.h"
#include "../GeometryLibrary/Shape.h"
#include <sstream>
#include <vector>
#include <algorithm>
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
    Polygon p(std::initializer_list<Point>(testPoints.data(), testPoints.data() + testPoints.size()), screenWidth, screenHeight);
    EXPECT_EQ(p.getPoint(0), Point(0, 0));
    EXPECT_EQ(p.getPoint(1), Point(0, 10));
}

TEST_F(PolygonTest, CoordsListConstructor) {
    Polygon p(std::initializer_list<std::pair<int, int >>(testCoords.data(), testCoords.data() + testCoords.size()), screenWidth, screenHeight);
    EXPECT_EQ(p.getPoint(0), Point(0, 0));
    EXPECT_EQ(p.getPoint(1), Point(0, 5));
}

TEST_F(PolygonTest, CopyConstructor) {
    Polygon p1(std::initializer_list<Point>(testPoints.data(), testPoints.data() + testPoints.size()), screenWidth, screenHeight);
    Polygon p2(p1);

    EXPECT_EQ(p2.getPoint(0), Point(0, 0));
    EXPECT_EQ(p2.getScreenWidth(), screenWidth);
}

TEST_F(PolygonTest, MoveConstructor) {
    Polygon p1(std::initializer_list<Point>(testPoints.data(), testPoints.data() + testPoints.size()), screenWidth, screenHeight);
    Polygon p2(std::move(p1));

    EXPECT_EQ(p2.getPoint(0), Point(0, 0));
    EXPECT_TRUE(p1.toString().find("[]") != std::string::npos);  // Проверяем что p1 пуст
}

TEST_F(PolygonTest, AssignmentOperator) {
    Polygon p1(std::initializer_list<Point>(testPoints.data(), testPoints.data() + testPoints.size()), screenWidth, screenHeight);
    Polygon p2(screenWidth, screenHeight);
    p2 = p1;

    EXPECT_EQ(p2.getPoint(0), Point(0, 0));
}

TEST_F(PolygonTest, ValidationChecks) {
    // Недостаточно точек
    std::vector<Point> NotEnoughPoints = { {0,0}, {1,1} };
    EXPECT_THROW(Polygon(std::initializer_list<Point>(NotEnoughPoints.data(), NotEnoughPoints.data() + NotEnoughPoints.size()), screenWidth, screenHeight), std::invalid_argument);

    // Совпадающие точки
    std::vector<Point> MatchingPoints = { { 0,0 }, { 0,0 }, { 1,1 } };
    EXPECT_THROW(Polygon(std::initializer_list<Point>(MatchingPoints.data(), MatchingPoints.data() + MatchingPoints.size()), screenWidth, screenHeight), std::logic_error);

    // Коллинеарные точки
    std::vector<Point> CollinearPoints = { {0,0}, {1,1}, {2,2}, {3,3} };
    EXPECT_THROW(Polygon(std::initializer_list<Point>(CollinearPoints.data(), CollinearPoints.data() + CollinearPoints.size()), screenWidth, screenHeight), std::logic_error);

    // Точки за границами экрана
    std::vector<Point> PointsBeyondBorders = { {0,0}, {0,2000}, {2000,0} };
    EXPECT_THROW(Polygon(std::initializer_list<Point>(PointsBeyondBorders.data(), PointsBeyondBorders.data() + PointsBeyondBorders.size()), screenWidth, screenHeight), std::invalid_argument);
}

TEST_F(PolygonTest, DrawMethod) {
    Polygon p(std::initializer_list<Point>(testPoints.data(), testPoints.data() + testPoints.size()), screenWidth, screenHeight);
    testing::internal::CaptureStdout();
    p.draw();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_TRUE(output.find("Drawing shape") != std::string::npos);
    EXPECT_TRUE(output.find("(0; 0)") != std::string::npos);
}
