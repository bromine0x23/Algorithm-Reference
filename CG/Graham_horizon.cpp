// $O\left(n\lg n\right)$
struct GrahamHorizonCmp {
	bool operator()(Point const & lhs, Point const & rhs) const {
		return lhs.x < rhs.x || (lhs.x == rhs.x && lhs.y < rhs.y);
	}
};

vector<Point> Graham_horizon(vector<Point> & points) {
	if (points.size() < 3) {
		return points;
	}

	sort(points.begin(), points.end(), GrahamHorizonCmp());

	deque<Point> Upper;
	Upper.push_front(points[0]);
	Upper.push_front(points[1]);
	for (int i=2; i < points.size(); ++i) {
		while (Upper.size()>=2 && direct(Upper[1], Upper[0], points[i])<=0) {
			Upper.pop_front();
		}
		Upper.push_front(points[i]);
	}

	deque<Point> Lower;
	Lower.push_front(points[points.size()-1]);
	Lower.push_front(points[points.size()-2]);
	for (int i=points.size()-3; i >= 0; --i) {
		while (Lower.size()>=2 && direct(Lower[1], Lower[0], points[i])<=0) {
			Lower.pop_front();
		}
		Lower.push_front(points[i]);
	}

	Upper.pop_front();
	Lower.pop_front();
	vector<Point> ConvexHull(Upper.rbegin(), Upper.rend());
	ConvexHull.insert(ConvexHull.end(), Lower.rbegin(), Lower.rend());

	return ConvexHull;
}
