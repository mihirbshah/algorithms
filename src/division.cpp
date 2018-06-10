/*
 * division.cpp
 *
 *  Created on: Jan 17, 2018
 *      Author: mihir
 */
#include <iostream>
#include <math.h>

std::pair<int, int> division(int dividend, int divisor)
{
	if (divisor == 0) return std::make_pair(static_cast<int>(nan("")), static_cast<int>(nan("")));

	bool is_neg = false;

	// negate divisor/dividend is either of them is -ve
	// Also store the sign information for later
	if (divisor < 0)
	{
		divisor = abs(divisor); // can also be done by ~divisor + 1 (2's complement)
		is_neg = !is_neg;
	}

	if (dividend < 0)
	{
		dividend = abs(dividend); // can also be done by ~dividend + 1 (2's complement)
		is_neg = !is_neg;
	}

	int quotient = 1, denominator = divisor;

	// Keep doubling the divisor until it exceeds the dividend
	while (dividend > denominator)
	{
		denominator <<= 1;
		quotient <<= 1;
	}

	// At this point, we need to reduce the divisor just enough so that it is just smaller than dividend
	while (denominator > dividend)
	{
		denominator -= divisor;
		--quotient;
	}

	int remainder = dividend - denominator;

	if (is_neg)
		quotient = -quotient; // can also be done by 2's complement

	return std::make_pair(quotient, remainder);
}

/*int main()
{
	std::pair<int, int> res1 = division(43, 3);
	std::cout << "43 / 3 = quotient[" <<  res1.first << "], remainder[" << res1.second << "]" << std::endl;

	std::pair<int, int> res2 = division(43, -3);
	std::cout << "43 / -3 = quotient[" <<  res2.first << "], remainder[" << res2.second << "]" << std::endl;

	std::pair<int, int> res3 = division(-43, 3);
	std::cout << "-43 / 3 = quotient[" <<  res3.first << "], remainder[" << res3.second << "]" << std::endl;

	std::pair<int, int> res4 = division(-43, -3);
	std::cout << "-43 / -3 = quotient[" <<  res4.first << "], remainder[" << res4.second << "]" << std::endl;

	std::pair<int, int> res5 = division(-43, 0);
	std::cout << "-43 / 0 = quotient[" <<  res5.first << "], remainder[" << res5.second << "]" << std::endl;

	std::pair<int, int> res6 = division(19, 23);
	std::cout << "19 / 23 = quotient[" <<  res6.first << "], remainder[" << res6.second << "]" << std::endl;

	std::pair<int, int> res7 = division(0, 23);
	std::cout << "0 / 23 = quotient[" <<  res7.first << "], remainder[" << res7.second << "]" << std::endl;

	std::pair<int, int> res8 = division(46, 23);
	std::cout << "46 / 23 = quotient[" <<  res8.first << "], remainder[" << res8.second << "]" << std::endl;

	std::pair<int, int> res9 = division(23, 23);
	std::cout << "23 / 23 = quotient[" <<  res9.first << "], remainder[" << res9.second << "]" << std::endl;

	return 0;
}*/



