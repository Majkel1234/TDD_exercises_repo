#include <gmock/gmock.h>

class ExampleInterface
{
public:
    ExampleInterface()
    {
        open("...");
    }

    virtual int open(const char* filename){}
    virtual int close() = 0;
};

class MockExample : public ExampleInterface     //mock, ktory przeslania metody, ktore chcemy przetestowac
{
public:
    MockExample(){}
    MOCK_METHOD1(open, int(const char* filename));
    MOCK_METHOD0(close, int());
};

TEST(TestFixture, TestCase)
{
    MockExample obj;
    EXPECT_CALL(obj, open("...")).Times(1);    //(obiekt, metoda).oczekiwania(). ..                 [oczekiwanie wywolania metody 'open();']
    obj.open("...");                                                                                //(spelnienie oczekiwan)
}
