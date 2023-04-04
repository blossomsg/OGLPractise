#include <iostream>

int add_values(int value_x, int value_y) {
	int value = value_x + value_y;
	return value;
}

int sub_values(int value_x, int value_y) {
	int value = value_x - value_y;
	return value;
}

int mul_values(int value_x, int value_y) {
	int value = value_x * value_y;
	return value;
}

int div_values(int value_x, int value_y) {
	int value = value_x/ value_y;
	return value;
}

bool greater_values(int value_x, int value_y) {
	return(value_x > value_y);
}

bool smaller_values(int value_x, int value_y) {
	return(value_x < value_y);
}

int diameter_of_circle(int radius) {
	return radius * 2;
}

int metres_to_centimetres(int value) {
	return value * 100;
}

int main() {
	int value_x = 32;
	int value_y = 68;
	int radius = 3;
	int m = 5;
	std::cout << add_values(value_x, value_y) << std::endl;
	std::cout << sub_values(value_x, value_y) << std::endl;
	std::cout << mul_values(value_x, value_y) << std::endl;
	std::cout << div_values(value_y, value_x) << std::endl;
	std::cout << greater_values(value_y, value_x) << std::endl;
	std::cout << smaller_values(value_y, value_x) << std::endl;
	std::cout << diameter_of_circle(radius) << std::endl;
	std::cout << metres_to_centimetres(m) << std::endl;
}