#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <string>

double division(double arg1, double arg2){
    if(!arg1 || !arg2) throw std::string{"Przez 0 sie nie dzieli!"};
    return (arg1/arg2);
}


int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc,argv);
    return RUN_ALL_TESTS();
}

TEST(DivisionFunctionTests,preTest)
{
   // EXPECT_EQ(division(10,5),0);
}

TEST(DivisionFunctionTests, functionTestForValuesHigherThanZero)
{
    EXPECT_THAT(division(30,3),::testing::Eq(10));
}

TEST(DivisionFunctionTests, functionTestForValueEqualToZero)
{
    EXPECT_ANY_THROW(division(10,0));
}
