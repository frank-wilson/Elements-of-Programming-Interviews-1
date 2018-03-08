#include "Questions.hpp"

#include <boost/lexical_cast.hpp>

// Reverse an int by converting it to a string and traversing backwards.
int reverse_with_string_complexity_n(int x) {
	std::stringstream ss, tt;
	ss << x;
	std::string s = ss.str();
	for (auto rit = s.rbegin(); rit != s.rend(); rit += 1) {
		tt << *rit;
	}
	return boost::lexical_cast<int>(tt.str());
}

// Reverse an int using basic arithmetic operations.
int reverse_complexity_n(int x) {
	int reversed = 0;
	while (x) {
		reversed = (reversed * 10) + (x % 10);
		x /= 10;
	}
	return reversed;
}

std::string eopi_0408(int x) {
	std::stringstream ss;
	ss << x << " reversed is " << reverse_complexity_n(x);
	return ss.str();
}