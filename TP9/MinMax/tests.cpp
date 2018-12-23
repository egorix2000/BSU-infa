#include <gtest/gtest.h>
#include <cctype>
#include <string>
#include "Stack.h"
#include "findValueOfExpression.h"

class MinMaxFixture : public ::testing::Test {

protected:
    virtual void TearDown() {
        delete stack;
    }

    virtual void SetUp() {
        stack = new Stack<int>();
    }

    Stack<int>* stack;
    std::string s;
};


TEST_F(MinMaxFixture, Number1) {
    stack->reset();
    s = "5";
    EXPECT_EQ(5, findValueOfExpression(s.c_str(), *stack));
}

TEST_F(MinMaxFixture, Number2) {
    stack->reset();
    s = "0";
    EXPECT_EQ(0, findValueOfExpression(s.c_str(), *stack));
}

TEST_F(MinMaxFixture, Number3) {
    stack->reset();
    s = "9";
    EXPECT_EQ(9, findValueOfExpression(s.c_str(), *stack));
}

TEST_F(MinMaxFixture, Simple1) {
    stack->reset();
    s = "min(3, 4)";
    EXPECT_EQ(3, findValueOfExpression(s.c_str(), *stack));
}

TEST_F(MinMaxFixture, Simple2) {
    stack->reset();
    s = "max(3, 5)";
    EXPECT_EQ(5, findValueOfExpression(s.c_str(), *stack));
}

TEST_F(MinMaxFixture, OneNested1) {
    stack->reset();
    s = "max(min(6, 3), 7)";
    EXPECT_EQ(7, findValueOfExpression(s.c_str(), *stack));
}

TEST_F(MinMaxFixture, OneNested2) {
    stack->reset();
    s = "max(min(9, 8), 0)";
    EXPECT_EQ(8, findValueOfExpression(s.c_str(), *stack));
}

TEST_F(MinMaxFixture, OneNested3) {
    stack->reset();
    s = "max(7, min(6, 3))";
    EXPECT_EQ(7, findValueOfExpression(s.c_str(), *stack));
}

TEST_F(MinMaxFixture, OneNested4) {
    stack->reset();
    s = "max(0, min(9, 8))";
    EXPECT_EQ(8, findValueOfExpression(s.c_str(), *stack));
}

TEST_F(MinMaxFixture, OneNested5) {
    stack->reset();
    s = "min(max(5, 6), 3)";
    EXPECT_EQ(3, findValueOfExpression(s.c_str(), *stack));
}

TEST_F(MinMaxFixture, OneNested6) {
    stack->reset();
    s = "min(max(1, 2), 3)";
    EXPECT_EQ(2, findValueOfExpression(s.c_str(), *stack));
}

TEST_F(MinMaxFixture, OneNested7) {
    stack->reset();
    s = "min(3, max(5, 6))";
    EXPECT_EQ(3, findValueOfExpression(s.c_str(), *stack));
}

TEST_F(MinMaxFixture, OneNested8) {
    stack->reset();
    s = "min(3, max(1, 2))";
    EXPECT_EQ(2, findValueOfExpression(s.c_str(), *stack));
}

TEST_F(MinMaxFixture, OneNested9) {
    stack->reset();
    s = "max(min(3, 2), 5)";
    EXPECT_EQ(5, findValueOfExpression(s.c_str(), *stack));
}

TEST_F(MinMaxFixture, TwoNested1) {
    stack->reset();
    s = "min(max(1, 2), max(3, 4))";
    EXPECT_EQ(2, findValueOfExpression(s.c_str(), *stack));
}

TEST_F(MinMaxFixture, TwoNested2) {
    stack->reset();
    s = "min(max(3, 4), max(1, 2))";
    EXPECT_EQ(2, findValueOfExpression(s.c_str(), *stack));
}

TEST_F(MinMaxFixture, TwoNested3) {
    stack->reset();
    s = "max(min(1, 2), min(3, 4))";
    EXPECT_EQ(3, findValueOfExpression(s.c_str(), *stack));
}

TEST_F(MinMaxFixture, TwoNested4) {
    stack->reset();
    s = "max(min(3, 4), min(1, 2))";
    EXPECT_EQ(3, findValueOfExpression(s.c_str(), *stack));
}

TEST_F(MinMaxFixture, TwoNested5) {
    stack->reset();
    s = "max(max(1, 2), max(3, 4))";
    EXPECT_EQ(4, findValueOfExpression(s.c_str(), *stack));
}

TEST_F(MinMaxFixture, TwoNested6) {
    stack->reset();
    s = "min(min(1, 2), min(3, 4))";
    EXPECT_EQ(1, findValueOfExpression(s.c_str(), *stack));
}

TEST_F(MinMaxFixture, TwoNested7) {
    stack->reset();
    s = "min(min(5, 6), max(3, 4))";
    EXPECT_EQ(4, findValueOfExpression(s.c_str(), *stack));
}

TEST_F(MinMaxFixture, TwoNested8) {
    stack->reset();
    s = "max(min(5, 6), max(3, 4))";
    EXPECT_EQ(5, findValueOfExpression(s.c_str(), *stack));
}

TEST_F(MinMaxFixture, ThreeNested1) {
    stack->reset();
    s = "min(min(min(2, 3), 1), 2)";
    EXPECT_EQ(1, findValueOfExpression(s.c_str(), *stack));
}