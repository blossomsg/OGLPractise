#include<iostream>
#include<iomanip>

int main() {
	// increment addition
	long values_01[]{ 1,2,3,4,5,6,7,8,9 };
	
	long save_values_01{};
	for (size_t i{}; i < std::size(values_01); ++i) {
		save_values_01 += values_01[i];
	}
	std::cout << "The sum of values_01 are " << save_values_01 << std::endl;

	// floating point loop
	const double pi{ 3.14159265358979323846 };
	const size_t perline{ 3 };
	size_t linecount{};
	for (double radius{ 0.2 }; radius <= 3.0; radius += 0.2) {
		//std::cout << "radius = " << std::setw(1) << radius << "area = " << std::setw(1) << pi * radius * radius << std::endl;
		std::cout << std::fixed << std::setprecision(2) << "\n" << "radius =" << std::setw(5) << radius << "\n" << "area =" << std::setw(6) << pi * radius * radius;
	}
		// When perline outputs have been written
		if(perline == ++linecount) {
			std::cout << std::endl;
			linecount = 0;
		}
		std::cout << std::endl;

	// factorial
		unsigned int limit{};
		std::cout << "This program calculates n! and the sum of the integers" << "up to n for values 1 to limit .\n";
		std::cout << "What upper limit for n would you like?";
		std::cin >> limit;

		// Output column heading
		std::cout << std::setw(8) << "integer" << std::setw(8) << "sum" << std::setw(20) << "factorial" << std::endl;
		for (unsigned long long n{ 1 }, sum{}, factorial{ 1 }; n <= limit; ++n) {
			sum += n;
			factorial *= n;
			std::cout << std::setw(8) << n << std::setw(8) << sum << std::setw(20) << factorial << std::endl;
		}

	int i{ 1 };
	int value_02{ 1 };
	int value_03{ 1 };
	int value_04{ 1 };

	std::cout << (value_02 += ++i, value_03 += ++i, value_04 += ++i) << std::endl;

}