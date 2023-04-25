#include <gtest/gtest.h>
extern "C" {
    #include "calculator.h"
}

TEST(CalculatorTest, Add) {
    EXPECT_NEAR(add(5, 4), 9.0, 0.01);
}

TEST(CalculatorTest, Subtract) {
    EXPECT_NEAR(subtract(5, 4), 1.0, 0.01);
}

TEST(CalculatorTest, Multiply) {
    EXPECT_NEAR(multiply(5, 4), 20.0, 0.01);
}

TEST(CalculatorTest, Divide) {
    EXPECT_NEAR(divide(10, 5), 2.0, 0.01);
}

TEST(CalculatorTest, Modulus) {
    EXPECT_NEAR(modulus(10, 3), 1.0, 0.01);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}