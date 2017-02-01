#include <cstdlib>
#include <iostream>
#include "interest_calc.h"

int main(int argc, char* argv[])
{
    if (argc != 3)
    {
	std::cout << "Usage: program <interest> <value>" << std::endl;
	return 1;
    }

    double rate = atof(argv[1]);
    double val = atof(argv[2]);

    InterestCalc int_calc(rate);

    double rate_ret = int_calc.single_period(val);
    std::cout << "Single Period Interest Return: " << rate_ret << std::endl;
    return 0;
}
