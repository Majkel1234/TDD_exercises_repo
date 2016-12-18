#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <iostream>
#include <vector>

class MyClass
{
public:
    MyClass(std::string _text): text{std::move(_text)}{}
    std::string getText()
    {
        if(text == "Zaba" || text == "Mrowka") return "";
        return text;
    }
private:
    std::string text;
};

struct myFixtureClass : ::testing::TestWithParam<std::string>
{
    MyClass myObj{GetParam()};
    std::string getThisParameter()
    {
        return myObj.getText();
    }
    void SetUp()
    {
        std::cout<<"Test dla argumentu ["<<GetParam()<<"]."<<std::endl;
    }
};

TEST_P(myFixtureClass, test01)
{
    EXPECT_THAT(getThisParameter(),::testing::Eq(GetParam()));
}

INSTANTIATE_TEST_CASE_P(InstantiationName, myFixtureClass,
                        ::testing::Values("Kot","Pies","Chomik","Zaba",
                                          "Mrowka"));
// Przyklad 2
std::vector<int> vect{1,0,3,0,5};
class myFixtureClass2 : public ::testing::TestWithParam<int>
{
public:
    myFixtureClass2()
    {
        ++counter;
    }
    static void SetUpTestCase()
    {
        std::cout<<"Testujemy inkrementujacy licznik VS parametry wektora."<<std::endl;
    }
    int getCounterValue()
    {
        return counter;
    }
private:
    static int counter;
};
int myFixtureClass2::counter = 0;

TEST_P(myFixtureClass2, counterIncrementationTest)
{
    EXPECT_THAT(getCounterValue(),::testing::Eq(GetParam()));
}

INSTANTIATE_TEST_CASE_P(someRandomName, myFixtureClass2, ::testing::ValuesIn(vect));


