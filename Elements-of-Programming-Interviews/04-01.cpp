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

// Right propagate the rightmost set bit in x, like (01010000) to (01011111).
unsigned long right_propagate_rightmost_bit(unsigned long x) {
	auto right_zeroes = 0;
	while ((x & 1) == 0) {
		right_zeroes += 1;
		x >>= 1;
	}
	x <<= right_zeroes;
	x |= (static_cast<long>(pow(2, right_zeroes) - 1));
	return x;
}

// Tests if input is power of 2 in O(1).
bool is_power_2_complexity_1(unsigned long x) {
	return (x & (x - 1)) == 0;
}

// Compute x mod a power of two. Return 13 for 77 mod 64.
signed long mod_power_2(unsigned long x, unsigned long power=64) {
	if (!is_power_2_complexity_1(power)) {
		return -1;
	}
	else if (x < power) {
		return x;
	}
	else if (is_power_2_complexity_1(x)) {
		return 0;
	}
	else {
		return x & (power - 1);
	}
}

std::string eopi_0401(unsigned long const x) {
	std::stringstream ss;
	ss << x << " has a parity of " << parity_complexity_log_n(x);
	return ss.str();
}