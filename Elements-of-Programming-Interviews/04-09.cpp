#include "Questions.hpp"

// Solution to 4-8 with an equality test tacked on.
bool is_palindrome_complexity_n(int x) {
	int reversed = 0;
	int x_copy = x;
	while (x_copy) {
		reversed = (reversed * 10) + (x_copy % 10);
		x_copy /= 10;
	}
	return (reversed == x);
}

std::string eopi_0409() {
	int x = 505051, y = 1220221;
	std::stringstream ss;
	ss << x << " is " << (is_palindrome_complexity_n(x) ? "" : "not ") << "a palindrome." << std::endl;
	ss << y << " is " << (is_palindrome_complexity_n(y) ? "" : "not ") << "a palindrome." << std::endl;
	return ss.str();
}