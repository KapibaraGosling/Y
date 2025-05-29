#include "pch.h"

#include "gtest/gtest.h"
#include "../DequeLibrary/Dequeue.h"

TEST(DequeTest, DefaultConstructor) {
    Deque<int> dq;
    EXPECT_TRUE(dq.empty());
    EXPECT_EQ(dq.size(), 0);
}

TEST(DequeTest, InitializerListConstructor) {
    Deque<int> dq = { 1, 2, 3 };
    EXPECT_EQ(dq.size(), 3);
    EXPECT_EQ(dq.front(), 1);
    EXPECT_EQ(dq.back(), 3);
}

TEST(DequeTest, PushFront) {
    Deque<int> dq;
    dq.push_front(1);
    EXPECT_EQ(dq.front(), 1);
    EXPECT_EQ(dq.size(), 1);

    dq.push_front(2);
    EXPECT_EQ(dq.front(), 2);
    EXPECT_EQ(dq.size(), 2);
}

TEST(DequeTest, PushBack) {
    Deque<int> dq;
    dq.push_back(1);
    EXPECT_EQ(dq.back(), 1);
    EXPECT_EQ(dq.size(), 1);

    dq.push_back(2);
    EXPECT_EQ(dq.back(), 2);
    EXPECT_EQ(dq.size(), 2);
}

TEST(DequeTest, PopFront) {
    Deque<int> dq = { 1, 2, 3 };
    dq.pop_front();
    EXPECT_EQ(dq.front(), 2);
    EXPECT_EQ(dq.size(), 2);

    dq.pop_front();
    EXPECT_EQ(dq.front(), 3);
    EXPECT_EQ(dq.size(), 1);
}

TEST(DequeTest, PopBack) {
    Deque<int> dq = { 1, 2, 3 };
    dq.pop_back();
    EXPECT_EQ(dq.back(), 2);
    EXPECT_EQ(dq.size(), 2);

    dq.pop_back();
    EXPECT_EQ(dq.back(), 1);
    EXPECT_EQ(dq.size(), 1);
}

TEST(DequeTest, PopEmptyDeque) {
    Deque<int> dq;
    EXPECT_THROW(dq.pop_front(), std::out_of_range);
    EXPECT_THROW(dq.pop_back(), std::out_of_range);
}

TEST(DequeTest, FrontBackEmptyDeque) {
    Deque<int> dq;
    EXPECT_THROW(dq.front(), std::out_of_range);
    EXPECT_THROW(dq.back(), std::out_of_range);
}

TEST(DequeTest, OperatorAccess) {
    Deque<int> dq = { 10, 20, 30 };
    EXPECT_EQ(dq[0], 10);
    EXPECT_EQ(dq[1], 20);
    EXPECT_EQ(dq[2], 30);
    EXPECT_THROW(dq[3], std::out_of_range);
}

TEST(DequeTest, CopyConstructor) {
    Deque<int> dq1 = { 1, 2, 3 };
    Deque<int> dq2(dq1);

    EXPECT_EQ(dq1.size(), dq2.size());
    EXPECT_EQ(dq1.front(), dq2.front());
    EXPECT_EQ(dq1.back(), dq2.back());
}

TEST(DequeTest, MoveConstructor) {
    Deque<int> dq1 = { 1, 2, 3 };
    Deque<int> dq2(std::move(dq1));

    EXPECT_TRUE(dq1.empty());
    EXPECT_EQ(dq2.size(), 3);
    EXPECT_EQ(dq2.front(), 1);
    EXPECT_EQ(dq2.back(), 3);
}

TEST(DequeTest, AssignmentOperator) {
    Deque<int> dq1 = { 1, 2, 3 };
    Deque<int> dq2;
    dq2 = dq1;

    EXPECT_EQ(dq1.size(), dq2.size());
    EXPECT_EQ(dq1.front(), dq2.front());
    EXPECT_EQ(dq1.back(), dq2.back());
}

TEST(DequeTest, ToString) {
    Deque<int> dq = { 1, 2, 3 };
    EXPECT_EQ(dq.toString(), "[1, 2, 3]");

    Deque<std::string> str_deque = { "a", "b", "c" };
    EXPECT_EQ(str_deque.toString(), "[a, b, c]");
}

TEST(DequeTest, StreamOutput) {
    Deque<int> dq = { 1, 2, 3 };
    std::ostringstream oss;
    oss << dq;
    EXPECT_EQ(oss.str(), "[1, 2, 3]");
}

TEST(DequeTest, ComplexOperations) {
    Deque<int> dq;
    EXPECT_TRUE(dq.empty());

    dq.push_back(1);
    dq.push_front(0);
    dq.push_back(2);

    EXPECT_EQ(dq.size(), 3);
    EXPECT_EQ(dq.toString(), "[0, 1, 2]");

    dq.pop_front();
    dq.pop_back();

    EXPECT_EQ(dq.size(), 1);
    EXPECT_EQ(dq.front(), 1);
    EXPECT_EQ(dq.back(), 1);

    dq.pop_front();
    EXPECT_TRUE(dq.empty());
}