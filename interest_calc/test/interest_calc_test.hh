#pragma once

#include "gtest/gtest.h"
#include "interest_calc.h"

struct InterestCalcTest: testing::Test
{
    InterestCalc* calc;

    InterestCalcTest(){}
    
    ~InterestCalcTest(){}

    virtual void SetUp()
    {
	calc = new InterestCalc(0.05);
    }

    virtual void TearDown()
    {
	delete calc;
    }
};

TEST_F(InterestCalcTest, SinglePeriod)
{
    EXPECT_EQ(105.00, calc->single_period(100.00));
}
