#pragma once

template <typename T>
void swap(std::vector<T>& a, int i, int j) {
	if (i < 0 || j < 0 || i >= a.size() || j >= a.size()) {
		return;
	}
	T tmp = a[i];
	a[i] = a[j];
	a[j] = tmp;
}

template <typename T>
std::string ToString(const std::vector<T> a) {
	std::stringstream ss;
	ss << "<";
	for (auto i = a.begin(); i != a.end() - 1; i++) {
		ss << *i << ", ";
	}
	ss << a.back();
	ss << ">";
	return ss.str();
}

template <typename T>
std::string ToString(const std::vector<std::vector<T>> a) {
	std::stringstream ss;
	ss << "<";
	for (auto i = a.begin(); i != a.end() - 1; i++) {
		ss << ToString(*i) << ", ";
	}
	ss << ToString(a.back());
	ss << ">";
	return ss.str();
}