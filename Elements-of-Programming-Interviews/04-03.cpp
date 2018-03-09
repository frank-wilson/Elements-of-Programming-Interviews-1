#include "Questions.hpp"

// Given a 64-bit unsigned integer and two indices, swap bits at indices.
unsigned long long swap_bits(unsigned long long x, int i, int j) {
	int const num_bits = sizeof(x) * 8;
	if (((x >> i) & 1) != ((x >> j) & 1)) {
		x ^= ((1LL << i) | (1LL << j));
	}
	return x;
}

// Reverse the bits of a 64-bit unsigned integer.
unsigned long long reverse_bits_complexity_n(unsigned long long x) {
	int const num_bits = sizeof(x) * 8;
	for (int i = num_bits - 1; i > num_bits/2; i--) {
		x = swap_bits(x, i, num_bits - i - 1);
	}
	return x;
}

std::string eopi_0403(unsigned long long x) {
	std::stringstream ss;
	ss << x << " reversed is " << reverse_bits_complexity_n(x);
	return ss.str();
}