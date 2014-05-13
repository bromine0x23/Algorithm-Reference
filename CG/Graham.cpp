// $O\left(n\lg n\right)$
struct GrahamCmp {
	bool operator()(Point2D const & lhs, Point2D const & rhs) const {
		return lhs.x < rhs.x || (lhs.x == rhs.x && lhs.y < rhs.y);
	}
};
std::vector<Point2D> Graham(std::vector<Point2D> & points) {
	int const POINT_NUM = points.size();
	if (POINT_NUM < 3) {
		return points;
	}
	std::sort(points.begin(), points.end(), GrahamCmp());
	std::deque<Point2D> U;
	U.push_front(points[0]);
	U.push_front(points[1]);
	for (int i = 2; i < POINT_NUM; ++i) {
		while (U.size() >= 2 && direct(U[1], U[0], points[i]) != RIGHT) {
			U.pop_front();
		}
		Upper.push_front(points[i]);
	}
	std::deque<int> L;
	L.push_front(points[POINT_NUM - 1]);
	L.push_front(points[POINT_NUM - 2]);
	for (int i=POINT_NUM - 3; i >= 0; --i) {
		while (L.size() >= 2 && direct(L[1], L[0], points[i]) != RIGHT) {
			L.pop_front();
		}
		L.push_front(points[i]);
	}
	U.pop_front();
	L.pop_front();
	std::vector<Point2D> CH;
	CH.reserve(U.size() + L.size());
	CH.insert(CH.end(), U.rbegin(), U.rend());
	CH.insert(CH.end(), L.rbegin(), L.rend());
	return CH;
}
