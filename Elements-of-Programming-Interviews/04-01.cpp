#include "Questions.hpp"

// Counts the number of 1's in binary representation of input.
// This runs in O(n), where n is the number of bits in binary form.
short count_bits_complexity_n(unsigned int x) {
	short num_bits = 0;
	while (x) {
		num_bits += x & 1;
		x >>= 1;
	}
	return num_bits;
}

// Parity is 0 if number of 1's in binary form is even. 1 if odd.
// This runs in O(n), where n is the number of bits in binary form.
short parity_complexity_n(unsigned long x) {
	short result = 0;
	while (x) {
		result ^= (x & 1);
		x >>= 1;
	}
	return result;
}


// Parity is 0 if number of 1's in binary form is even. 1 if odd.
// This runs in O(k), where k is the number of 1 bits in binary form.
short parity_complexity_k(unsigned long x) {
	short result = 0;
	while (x) {
		result ^= 1;
		x &= (x - 1);
	}
	return result;
}

// Parity is 0 if number of 1's in binary form is even. 1 if odd.
// This runs in O(log n), exploiting the fact that XOR is assoc.,
// meaning (w ^ x ^ y ^ z) = (w ^ x) ^ (y ^ z)
short parity_complexity_log_n(unsigned long x) {
	x ^= x >> 16; // Apparently Visual Studio unsigned long has 32 bits!
	x ^= x >> 8;
	x ^= x >> 4;
	x ^= x >> 2;
	x ^= x >> 1;
	return x & 1;
}

// Tests if input is power of 2 in O(1).
bool test_power_2_complexity_1(unsigned long x) {
	return (x & (x - 1)) == 0;
}

std::string eopi_0401(unsigned long const x) {
	std::stringstream ss;
	ss << x << " has a parity of " << parity_complexity_log_n(x);
	return ss.str();
}