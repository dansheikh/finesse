#include "interest_calc.h"

InterestCalc::InterestCalc(double rate)
    : rate(rate)
{
}

InterestCalc::InterestCalc(const InterestCalc& rhs)
    : rate(rhs.rate)
{
}

InterestCalc::~InterestCalc()
{
}

InterestCalc& InterestCalc::operator=(const InterestCalc& rhs)
{
    if (&rhs != this)
    {
	this->rate = rhs.rate;
    }
    return *this;
}

double InterestCalc::single_period(double value)
{
    return value * (1 + this->rate);
}
