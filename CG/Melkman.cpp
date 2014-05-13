std::vector<Point2D> Melkman(std::vector<Point2D> const & points) {
	int const POINT_NUM = points.size();
	if (POINT_NUM < 3) {
		return points;
	}
	std::deque<Point2D> CH;
	CH.push_back(points[0]);
	CH.push_back(points[1]);
	int i = 2;
	for (; i < POINT_NUM; ++i) {
		if (direct(CH[0], CH[1], points[i]) != STRIGHT) {
			CH.push_front(i);
			CH.push_back(i);
			break;
		}
		CH[1] = points[i];
	}
	if (direct(CH[0], CH[1], CH[2]) == LEFT) {
		swap(CH[0], CH[2]);
	}
	for (++i; i < POINT_NUM; ++i) {
		for (; direct(CH[1], CH[0], points[i]) != LEFT; ) {
			CH.pop_front();
		}
		CH.push_front(points[i]);
		for (; direct(CH[CH.size() - 2], CH[CH.size() - 1], points[i]) != LEFT; ) {
			CH.pop_back();
		}
		CH.push_back(points[i]);
	}
	return std::vector<Point2D>(CH.begin(), CH.end());
}
