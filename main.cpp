#include <cstdlib>
#include <iostream>
#include <cmath> // for std::abs()


bool approximatelyEqualRel(double a, double b, double relEpsilon)
{
    return (std::abs(a - b) <= ( std::max(std::abs(a), std::abs(b)) * relEpsilon ));
	//relEpsilon means relative Epsilon
}

bool approximatelyEqualAbsRel(double a, double b, double absEpsilon, double relEpsilon)
{
	
	double diff{std::abs(a - b)};
	
	//Case 1: check if the numbers are really close -- needed when comparing numbers near zero (small gap of precision)
	// really small gap -> compare the gap with absolute Epsilon 1e-12
	if (diff <= absEpsilon)
		return true;

	//Case 2: fall back to Knuth's alogrithm (huge gap of precision like 0.999 and 1.0)
	//Huger gap -> 0.1 or 0.001 (usually 8 numbers before the colon) -> use relative epsilon 1e-8 
	return (diff <= ( std::max(std::abs(a), std::abs(b)) * relEpsilon ));
}

int main() 
{ 
	// a is really close to 1.0, but it's slightly smaller than 1.0
	double a{ 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 };

	//Relative epsilon number is usually close to 1e-8 (1 x 10 ^ -8)

	// std::cout << approximatelyEqualRel(a, 1.0, 1e-8) << '\n';
	// std::cout << approximatelyEqualRel(a-1.0, 0.0, 1e-8) << '\n';

	std::cout << approximatelyEqualAbsRel(a, 1.0, 1e-12, 1e-8);
	std::cout << approximatelyEqualAbsRel(a - 1.0, 0.0, 1e-12, 1e-8); 



}