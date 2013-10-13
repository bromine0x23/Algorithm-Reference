vector<Point> Melkman(vector<Point> const & points) {
	if (points.size() < 3) {
		return points;
	}

	deque<Point> C;

	C.push_back(points[0]);
	if (direct(points[0], points[1], points[2])<=0) {
		C.push_back(points[1]);
		C.push_back(points[2]);
		C.push_front(points[2]);
	} else {
		C.push_back(points[2]);
		C.push_back(points[1]);
		C.push_front(points[1]);
	}

	for (int i=3; i < points.size(); ++i) {

	}
}
