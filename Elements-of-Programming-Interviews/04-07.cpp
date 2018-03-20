#include "Questions.hpp"

// Iterative solution from book. Too confusing for me.
double power_iterative_complexity_n(double x, int y) {
	if (y < 0) {
		y = -y, x = 1 / x;
	}
	double acc = 1;
	while (y) {
		if (y & 1) {
			acc *= x;
		}
		x *= x;
		y >>= 1;
	}
	return acc;
}

// We'll only have a max of 32 stack frames, so recursion isn't so bad.
double power_recursive(double x, int y) {
	if (y < 0) {
		y = -y, x = 1 / x;
	}
	if (y == 1) {
		return x;
	}
	if ((y & 1) == 0) {
		return power_recursive(x, y >> 1) * power_recursive(x, y >> 1);
	}
	if ((y & 1) == 1) {
		return power_recursive(x, y >> 1) * power_recursive(x, y >> 1) * x;
	}
	return -1;
}

std::string eopi_0407() {
	double x = 0.5;
	int y = 3;
	std::stringstream ss;
	ss << x << " to the power of " << y << " is " << power_recursive(x, y);
	return ss.str();
}