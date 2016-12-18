#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "calculator.h"

class CalculatorTestSuite : public ::testing::Test
{
public:
    CalculatorTestSuite() = default;
    ~CalculatorTestSuite() = default;
    void SetUp()
    {
        std::cout<<"Rozpoczynam test nr ["<<++counter<<"]"<<std::endl;
    }
    void TearDown()
    {
        std::cout<<"Koncze test nr ["<<counter<<"]"<<std::endl;
    }
    static void SetUpTestCase()
    {
        std::cout<<"*** ROZPOCZYNAM TESTOWANIE ***"<<std::endl;
    }
    static void TearDownTestCase()
    {
        std::cout<<"*** KONIEC TESTOWANIA ***"<<std::endl;
    }
    Calculator calculator;
private:
    static int counter;
};
int CalculatorTestSuite::counter = 0;

TEST_F(CalculatorTestSuite, additionMethodTesting)
{
    auto additionResult = calculator.addition(10,5);
    EXPECT_THAT(additionResult,::testing::Eq(15));
}

TEST_F(CalculatorTestSuite, subtractionMethodTesting)
{
    auto subtractionResult = calculator.subtraction(50,10);
    EXPECT_THAT(subtractionResult,::testing::Eq(40));
}

TEST_F(CalculatorTestSuite, multiplicationMethodTesting)
{
    auto multiplicationResult = calculator.multiplication(3,5);
    EXPECT_THAT(multiplicationResult,::testing::Eq(15));
}

TEST_F(CalculatorTestSuite, divisionMethodTesting)
{
    auto divisionResult = calculator.division(15,2);
    EXPECT_THAT(divisionResult,::testing::Eq(7.5));
}

TEST_F(CalculatorTestSuite, divisionMethodTestingForValueZero)
{
    EXPECT_ANY_THROW(calculator.division(10,0));
}
