#include <iostream>

int main() {
	int value_x{ 7 };
	int value_zero{0}; // value 0
	long perimeter{};
	int width{ 25 };
	int length{ 33 };
	perimeter= 2 * (width * length);

	// what is define and initialize
	int initialize{}; // defined
	long initialize{ 17 }; //defined and initialized

	//sizeof to check the bytes consumed by the type variable
	std::cout << sizeof(width) << std::endl; // bracket helps to understand the selected variable

	//pointers
	long number{ 38 };
	auto* pnumber{ &number};
	

	// style of variables
	int value_zero_y();
	int value_zero_z = 0;

	const int trial{ 83 }; // always needs to be initialized 
	long long distance{ 15'00'00'000};

	std::cout << distance << std::endl;
	return 0;
}