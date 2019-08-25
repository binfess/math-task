#include <iostream>
#include <random>
#include <algorithm>

#include <cmath>

#include "cdarray.hpp"

int main(int argc, char **argv)
{
	CDArray<int> numbers(10);

	int max = 10, min = 0;

	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dis(min, max);

	for (int i = 1; i < 11; i++)
	{
		numbers.Add(i);
		std::cout << numbers[i-1] << ' ';
	}
	std::cout << std::endl;

	/* Sort array */
	std::cout << "After sort: " << std::endl;
	std::sort(numbers.Ptr(), numbers.Ptr() + numbers.Number());
	for (int i = 0; i < numbers.Number(); i++)
	{
		std::cout << numbers[i] << ' ';
	}
	std::cout << std::endl;

	/* Calc probablity */
	double probablity_val = 1.0 / (max-min);

	std::cout << "Probablity value: " << probablity_val << std::endl;

	/* Calc expected value */
	double expected_val{0};
	for (int i = 0; i < numbers.Number(); i++)
	{
		expected_val += numbers[i];
	}
	expected_val *= probablity_val;

	std::cout << "Expected value: " << expected_val << std::endl;

	/* Calc variance value */
	double variance_val{0};
	for (int i = 0; i < numbers.Number(); i++)
	{
		variance_val += std::pow(numbers[i], 2);
	}
	variance_val = variance_val * probablity_val - std::pow(expected_val, 2);

	std::cout << "Variance value: " << variance_val << std::endl;

	/* Calc standard deviation value */
	double deviation_val = std::sqrt(variance_val);

	std::cout << "Standard deviation: " << deviation_val << std::endl;

	return 0;
}