#include <gtest/gtest.h>
extern "C" {
    #include "shapes.h"
}
TEST(ShapesTest, RectangleArea) {
    EXPECT_NEAR(rectangle_area(5, 4), 20.0, 0.01);
}

TEST(ShapesTest, RectanglePerimeter) {
    EXPECT_NEAR(rectangle_perimeter(5, 4), 18.0, 0.01);
}

TEST(ShapesTest, ParallelogramArea) {
    EXPECT_NEAR(parallelogram_area(5, 4), 20.0, 0.01);
}

TEST(ShapesTest, ParallelogramPerimeter) {
    EXPECT_NEAR(parallelogram_perimeter(5, 4), 18.0, 0.01);
}

TEST(ShapesTest, TriangleArea) {
    EXPECT_NEAR(triangle_area(5, 4), 10.0, 0.01);
}

TEST(ShapesTest, TrianglePerimeter) {
    EXPECT_NEAR(triangle_perimeter(3, 4, 5), 12.0, 0.01);
}

TEST(ShapesTest, CircleArea) {
    EXPECT_NEAR(circle_area(5), 78.5398, 0.01);
}

TEST(ShapesTest, CircleCircumference) {
    EXPECT_NEAR(circle_circumference(5), 31.4159, 0.01);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}