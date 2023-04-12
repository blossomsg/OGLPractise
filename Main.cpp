#include <iostream>

void print_int(int value_x);

int main() {
	int some_value = 55;
	print_int(some_value);
	return 0;
}

void print_int(int value_x) {
	value_x += 33;
	std::cout <<  value_x << std::endl;
	return;
}