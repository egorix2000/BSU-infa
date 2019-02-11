#include <gtest/gtest.h>
#include "Triangle.h"

TEST(TriangleIsoscelesTest, isIsosceles1) {
    EXPECT_EQ(1, getTriangleType(3, 3, 5));
}

TEST(TriangleIsoscelesTest, isIsosceles2) {
    EXPECT_EQ(1, getTriangleType(3, 5, 3));
}

TEST(TriangleIsoscelesTest, isIsosceles3) {
    EXPECT_EQ(1, getTriangleType(5, 3, 3));
}

TEST(TriangleEquilateralTest, isEquilateral) {
    EXPECT_EQ(2, getTriangleType(5, 5, 5));
}

TEST(TriangleBigNumbersTest, isIsosceles1) {
    EXPECT_EQ(1, getTriangleType(4294967295, 4294967295, 1));
}

TEST(TriangleBigNumbersTest, isIsosceles2) {
    EXPECT_EQ(1, getTriangleType(4294967295, 1, 4294967295));
}

TEST(TriangleBigNumbersTest, isIsosceles3) {
    EXPECT_EQ(1, getTriangleType(1, 4294967295, 4294967295));
}

TEST(TriangleTest, DifferentEdges) {
    EXPECT_EQ(0, getTriangleType(4, 2, 3));
}

TEST(NotTriangleTest, ShortEdge1) {
    EXPECT_EQ(-1, getTriangleType(5, 2, 1));
}

TEST(NotTriangleTest, ShortEdge2) {
    EXPECT_EQ(-1, getTriangleType(2, 5, 1));
}

TEST(NotTriangleTest, ShortEdge3) {
    EXPECT_EQ(-1, getTriangleType(2, 1, 5));
}

TEST(NotTriangleTest, ShortEdgeStrictInequality1) {
    EXPECT_EQ(-1, getTriangleType(2, 2, 4));
}

TEST(NotTriangleTest, ShortEdgeStrictInequality2) {
    EXPECT_EQ(-1, getTriangleType(2, 4, 2));
}

TEST(NotTriangleTest, ShortEdgeStrictInequality3) {
    EXPECT_EQ(-1, getTriangleType(4, 2, 2));
}

TEST(NotTriangleTest, NegativeNumber1) {
    EXPECT_EQ(-1, getTriangleType(-1, -1, 3));
}

TEST(NotTriangleTest, NegativeNumber2) {
    EXPECT_EQ(-1, getTriangleType(-1, 3, -1));
}

TEST(NotTriangleTest, NegativeNumber3) {
    EXPECT_EQ(-1, getTriangleType(3, -1, -1));
}

TEST(NotTriangleTest, Zero1) {
    EXPECT_EQ(-1, getTriangleType(0, 2, 2));
}

TEST(NotTriangleTest, Zero2) {
    EXPECT_EQ(-1, getTriangleType(2, 0, 2));
}

TEST(NotTriangleTest, Zero3) {
    EXPECT_EQ(-1, getTriangleType(2, 2, 0));
}

TEST(NotTriangleTest, NotEnoughData1) {
    EXPECT_EQ(-1, getTriangleType(2, 2));
}

TEST(NotTriangleTest, NotEnoughData2) {
    EXPECT_EQ(-1, getTriangleType(2));
}

TEST(NotTriangleTest, NotEnoughData3) {
    EXPECT_EQ(-1, getTriangleType());
}