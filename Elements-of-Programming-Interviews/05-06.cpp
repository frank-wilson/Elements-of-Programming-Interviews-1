#include "Questions.hpp"
#include "VectorUtils.hpp"

double BuyAndSellStockOnce_complexity_n(const std::vector<double>& prices) {
	double min_price_so_far = std::numeric_limits<double>::max(), max_profit = 0;
	for (const double& price: prices) {
		if (price < min_price_so_far) {
			min_price_so_far = price;
		}
		price - min_price_so_far;
		if (price - min_price_so_far > max_profit) {
			max_profit = price - min_price_so_far;
		}
	}
	return max_profit;
}

std::string LongestEqualSubArray_complexity_n() {
	std::vector<int> ints = { 1, 1, 1, 2, 2, 3, 3, 3, 4 };
	int longest_subarray_len = 0, curr_subarray_len = 0, last_seen = ints[0];
	for (auto i = ints.begin() + 1; i != ints.end(); i++) {
		if (last_seen == *i) {
			++curr_subarray_len;
			if (curr_subarray_len > longest_subarray_len) {
				longest_subarray_len = curr_subarray_len;
			}
		}
		else {
			curr_subarray_len = 1;
		}
		last_seen = *i;
	}
	std::stringstream ss;
	ss << "The length of the longest contiguous equal subarray of " << ToString(ints);
	ss << " is " << longest_subarray_len;
	return ss.str();
}

std::string eopi_0506() {
	std::vector<double> prices = { 310, 315, 275, 295, 260, 270, 290, 230, 255, 250 };
	std::stringstream ss;
	ss << "The max profit of " << ToString(prices) << " is " << BuyAndSellStockOnce_complexity_n(prices);
	return ss.str();
}