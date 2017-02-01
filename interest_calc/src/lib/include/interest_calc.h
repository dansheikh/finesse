#pragma once

#include <iostream>

class InterestCalc
{
public:
    InterestCalc(double rate);
    InterestCalc(const InterestCalc& rhs);
    ~InterestCalc();
    InterestCalc& operator=(const InterestCalc& rhs);

    double single_period(double value);

private:
    double rate;
};
