#include <gtest/gtest.h>
extern "C" {
    #include "shapes.h"

class shapesTests : public testing::Test {
protected:
	void SetUp() override {
		//game_initialize();	/* Without this the Tests could break*/
	}
};
}

TEST_F(ShapesTests, RectangleArea) {
    //ARRANGE 
    double height = 5.0;
    double width = 4.0;
    double result;
    //ACT
    result = rectangle_area(height, width);
    //ASSERT
    ASSERT_NEAR(result, 20.0, 0.01); //5 x 4 = 20
}
TEST_F(ShapesTests, RectanglePerimeter) {
    //ARRANGE 
    double height = 5.0;
    double width = 4.0;
    double result;
    //ACT
    result = rectangle_perimeter(height, width);
    //ASSERT
    ASSERT_NEAR(result, 18.0, 0.01); //5 + 5 + 4 + 4 = 18
}

TEST_F(ShapesTests, ParallellogramArea) {
    //ARRANGE 
    double base = 5.0;
    double height = 4.0;
    double result;
    //ACT
    result = parallellogram_area(base, height);
    //ASSERT
    ASSERT_NEAR(result, 20.0, 0.01); 
}
TEST_F(ShapesTests, ParallellogramPerimeter) {
    //ARRANGE 
    double base = 5.0;
    double side = 4.0;
    double result;
    //ACT
    result = parallellogram_perimeter(base, side);
    //ASSERT
    ASSERT_NEAR(result, 18.0, 0.01); 
}

TEST_F(ShapesTests, TriangleArea) {
    //ARRANGE 
    double base = 5.0;
    double height = 4.0;
    double result;
    //ACT
    result = triangle_area(base, height);
    //ASSERT
    ASSERT_NEAR(result, 10.0, 0.01); 
}

TEST_F(ShapesTests, TrianglePerimeter) {
    //ARRANGE 
    double side1 = 3.0;
    double side2 = 4.0;
    double side3 = 5.0;
    double result;
    //ACT
    result = triangle_perimeter(side1, side2, side3);
    //ASSERT
    ASSERT_NEAR(result, 12.0, 0.01); 
}

TEST_F(ShapesTests, CircleArea){
    //ARRANGE
    double radius = 5.0;
    double result;
    //ACT
    result = circle_area(radius);
    //ASSERT
    ASSERT_NEAR(result, 78.5398, 0.01);
}

TEST_F(ShapesTests, CircleCircumference){
    //ASSERT
    double radius = 5.0;
    double result;
    //ACT
    result = circle_circumference(radius);
    ASSERT_NEAR(result, 31.4159, 0.01);
}


