#include <gtest/gtest.h> // Detta ska alltid stå med
extern "C" {
    #include "calculator.h" // inkludera alltid berörd .h fil.

class calculatorTests : public testing::Test {
protected:
	void SetUp() override {
		//game_initialize();	/* Without this the Tests could break*/
	}
};
}

TEST_F(calculatorTests, Add) {
    //ARRANGE 
    double a = 5.0;
    double b = 4.0;
    double result;
    //ACT
    result = add(a,b);
    //ASSERT
    ASSERT_NEAR(result, 9.0, 0.01);
}


TEST_F(calculatorTests, Substract) {
    //ARRANGE 
    double a = 5.0;
    double b = 4.0;
    double result;
    //ACT
    result = substract(a,b);
    //ASSERT
    ASSERT_NEAR(result, 1.0, 0.01);
}

TEST_F(calculatorTests, Multiply) {
    //ARRANGE 
    double a = 2.0;
    double b = 3.0;
    double result;
    //ACT
    result = multiply(a,b);
    //ASSERT
    ASSERT_NEAR(result, 6.0, 0.01);
}

TEST_F(calculatorTests, Divide) {
    //ARRANGE 
    double a = 6.0;
    double b = 2.0;
    double result;
    //ACT
    result = divide(a,b);
    //ASSERT
    ASSERT_NEAR(result, 3.0, 0.01);
}

TEST_F(calculatorTests, Modulus) { // What is left after a is divided by b.
    //ARRANGE 
    double a = 17.0;
    double b = 3.0;
    double result;
    //ACT
    result = modulus(a,b);
    //ASSERT
    ASSERT_NEAR(result, 2.0, 0.01);
}

/* HADE DET VARIT INTS:
TEST_F(CalculatorTest, Add) {
    //ARRANGE 
    int a = 5;
    int b = 4;
    int result;

    //ACT
    result = add(a, b);

    //ASSERT
    ASSERT_EQ(result, 9);
}



ENKLARE TEST, MEN KAN FAILA ATT TESTAS OM
TEST_F(calculatorTests, Subtract) { //TEST(Calculatortest, beskrivning av vad funktion testar)
    EXPECT_NEAR(subtract(5, 4), 1.0, 0.01); // EXEPCT-NEAR = en av många inbyggda funk för användning av flyttal. Blir ca detta.
} //5 - 4 (testvärden) blir 1.0 (förväntat värde), 0.01 (toleransnivå, förväntat värde får max skilja sig med 0.01 från testvärde.)

*/