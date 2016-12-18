#ifndef CALCULATOR_H
#define CALCULATOR_H
#include <string>

class Calculator{
public:
    Calculator(){}
    double addition(double arg1, double arg2)
    {
        return (arg1 + arg2);
    }
    double subtraction(double arg1, double arg2)
    {
        return (arg1 - arg2);
    }
    double multiplication(double arg1, double arg2)
    {
        return (arg1 * arg2);
    }
    double division(double arg1, double arg2)
    {
        if(!arg1 || !arg2)
        {
            throw std::string{"You cannot divide by 0!"};
        }
        return (arg1 / arg2);
    }
};

#endif // CALCULATOR_H
