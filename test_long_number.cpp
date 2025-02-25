#include <gtest/gtest.h>
#include "llo.hpp"

class LongNumberTest : public ::testing::Test {
protected:
    void SetUp() override {}
};
// Тест для конструктора и метода toString
TEST_F(LongNumberTest, ConstructorAndToString) {
    LongNumber num("123.456", 3);
    EXPECT_EQ(num.toString(), "123.456");
}

// Тест для сложения
TEST_F(LongNumberTest, Addition) {
    LongNumber num1("10.5", 3);
    LongNumber num2("20.25", 3);
    LongNumber result = num1 + num2;
    EXPECT_EQ(result.toString(), "30.75");
}

// Тест для вычитания
TEST_F(LongNumberTest, Subtraction) {
    LongNumber num1("30.75", 2);
    LongNumber num2("0", 2);
    LongNumber result = num1 - num2;
    EXPECT_EQ(result.toString(), "30.75");
}

// Тест для умножения
TEST_F(LongNumberTest, Multiplication) {
    LongNumber num1("10.5", 2);
    LongNumber num2("2.0", 2);
    LongNumber result = num1 * num2;
    EXPECT_EQ(result.toString(), "21");
}

// Тест для деления
TEST_F(LongNumberTest, Division) {
    LongNumber num1("21.0", 2);
    LongNumber num2("2.0", 2);
    LongNumber result = num1 / num2;
    EXPECT_EQ(result.toString(), "10.5");
}

// Тест для сравнения
TEST_F(LongNumberTest, Comparison) {
    LongNumber num1("10.5", 2);
    LongNumber num2("20.25", 2);
    EXPECT_TRUE(num1 < num2);
    EXPECT_FALSE(num1 > num2);
    EXPECT_TRUE(num1 != num2);
}