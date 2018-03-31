#include "Questions.hpp"
#include "VectorUtils.hpp"

void matrix_layer_in_clockwise(const std::vector<std::vector<int>>& square_matrix, int offset, std::vector<int>& spiral_ordering) {
	if (offset == square_matrix.size() - offset - 1) {
		spiral_ordering.push_back(square_matrix[offset][offset]);
		return;
	}
	for (int j = offset; j < square_matrix.size() - offset - 1; j++) {
		spiral_ordering.push_back(square_matrix[offset][j]);
	}
	for (int j = offset; j < square_matrix.size() - offset - 1; j++) {
		spiral_ordering.push_back(square_matrix[j][square_matrix.size() - offset - 1]);
	}
	for (int j = square_matrix.size() - offset - 1; j > offset; j--) {
		spiral_ordering.push_back(square_matrix[square_matrix.size() - offset - 1][j]);
	}
	for (int j = square_matrix.size() - offset - 1; j > offset; j--) {
		spiral_ordering.push_back(square_matrix[j][offset]);
	}
}

std::vector<int> matrix_in_spiral_order(const std::vector<std::vector<int>>& square_matrix) {
	std::vector<int> spiral_ordering;
	for (int offset = 0; offset < ceil(0.5 * square_matrix.size()); offset++) {
		matrix_layer_in_clockwise(square_matrix, offset, spiral_ordering);
	}
	return spiral_ordering;
}

std::string eopi_0518() {
	std::vector<std::vector<int>> a = { { 1, 2, 3, 4 }, { 5, 6, 7, 8 }, { 9, 10, 11, 12 }, { 13, 14, 15, 16 } };
	std::stringstream ss;
	ss << "Matrix " << ToString(a) << " yields " << ToString(matrix_in_spiral_order(a));
	return ss.str();
}