#include "Questions.hpp"

struct rectangle {
	int x, y, height, width;
};

std::string to_coordinates(rectangle& r) {
	std::stringstream ss;
	ss << "Coordinates of intersecting rectangle are " <<
		  "(" << r.x << ", " << r.y << "), " <<
		  "(" << r.x << ", " << r.y + r.height << "), " <<
		  "(" << r.x + r.width << ", " << r.y + r.height << "), " <<
		  "(" << r.x + r.width << ", " << r.y << "), "
	;
	return ss.str();
}

bool do_they_intersect(rectangle& r1, rectangle& r2) {
	return (r1.x + r1.width >= r2.x) && (r1.y + r1.height >= r2.y) &&
		   (r2.x + r2.width >= r1.x) && (r2.y + r2.height >= r1.y);
}

rectangle intersection_rectangles_complexity_1(rectangle& r1, rectangle& r2) {
	if (!do_they_intersect(r1, r2)) {
		return { 0, 0, -1, -1 };
	}
	return { std::max(r1.x, r2.x),
	         std::max(r1.y, r2.y),
			 std::min(r1.y + r1.height, r2.y + r2.height) - std::max(r1.y, r2.y),
			 std::min(r1.x + r1.width, r2.x + r2.width) - std::max(r1.x, r2.x),
		   };
}

std::string eopi_0411() {
	rectangle r1 = { 0, 0, 3, 5 };
	rectangle r2 = { 3, 2, 4, 5 };
	auto r3 = intersection_rectangles_complexity_1(r1, r2);
	return to_coordinates(r3);
}