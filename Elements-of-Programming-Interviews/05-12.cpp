#include "Questions.hpp"
#include "VectorUtils.hpp"

std::vector<int> grab_marbles_from_bag_complexity_n(int num_marbles, std::vector<int> a) {
	std::default_random_engine seed((std::random_device())());
	for (int i = 0; i < num_marbles; i++) {
		swap(a, i, std::uniform_int_distribution<int>{i, static_cast<int>(a.size() - 1) }(seed));
	}
	return std::vector<int>(a.begin(), a.begin() + num_marbles);
}

std::string eopi_0512() {
	std::vector<int> a = { 1, 2, 3, 4, 5 };
	int num_marbles = 2;
	std::stringstream ss;
	ss << "Picking " << num_marbles << " marbles randomly from jar " << ToString(a) << ". . .\n";
	ss << ToString(grab_marbles_from_bag_complexity_n(num_marbles, a));
	return ss.str();
}