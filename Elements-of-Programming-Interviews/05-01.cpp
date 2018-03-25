#include "Questions.hpp"
#include "EnumPrinter.hpp"

DEFINE_ENUM_WITH_STRING_CONVERSIONS(Color, (RED)(WHITE)(BLUE))

template <typename T>
void swap(std::vector<T>& a, int i, int j) {
	if (i < 0 || j < 0 || i >= a.size() || j >= a.size()) {
		return;
	}
	T tmp = a[i];
	a[i] = a[j];
	a[j] = tmp;
}

// Kind of a waste of time.
void DutchFlagPartition_complexity_n_2(int pivot_idx, std::vector<Color>& a) {
	Color pivot = a[pivot_idx];
	// Bubble all elements smaller than pivot to front.
	for (int i = 0; i < a.size(); i++) {
		for (int j = i + 1; j < a.size(); j++) {
			if (a[j] < pivot) {
				swap(a, i, j);
				break;
			}
		}
	}
	// Bubble all elements larger than pivot to back.
	for (int i = a.size() - 1; i >= 0; i--) {
		for (int j = i - 1; j >= 0 && a[j] >= pivot; j--) {
			if (a[j] > pivot) {
				swap(a, i, j);
				break;
			}
		}
	}
}

// Straight-forward!
void DutchFlagPartition_complexity_n(int pivot_idx, std::vector<Color>& a) {
	Color pivot = a[pivot_idx];
	int smaller = 0;
	for (int i = 0; i < a.size(); i++) {
		if (a[i] < pivot) {
			swap(a, smaller++, i);
		}
	}
	int larger = a.size() - 1;
	for (int i = a.size() - 1; i >= 0; i--) {
		if (a[i] > pivot) {
			swap(a, i, larger--);
		}
	}
}

std::string eopi_0501() {
	std::vector<Color> a = { BLUE, RED, RED, WHITE, RED, BLUE, RED, RED };
	int pivot_idx = 3;
	DutchFlagPartition_complexity_n(pivot_idx, a);
	std::stringstream ss;
	for (auto i = a.begin(); i != a.end(); i++) {
		ss << ToString(*i) << " ";
	}
	return ss.str();
}