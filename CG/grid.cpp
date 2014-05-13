// assume ValType = int
// count amount of points on polygon's edge
int count_onedge(std::vector<Point2D> P) {
	int const POINT_NUM = P.size();
	int ans = 0;
	for (int i = 0; i < POINT_NUM; ++i) {
		ans += Euclid(abs(P[i].x - P[(i + 1) % POINT_NUM].x), abs(P[i].y - P[(i + 1) % POINT_NUM].y));
	}
	return ans;
}
// count amount of points in polygon
int count_inside(std::vector<Point2D> P) {
	int const POINT_NUM = P.size();
	int ans = 0;
	for (int i = 0; i < POINT_NUM; ++i) {
		ans += P[(i + 1) % POINT_NUM].y * (P[i].x - P[(i + 2) % POINT_NUM].x);
	}
	return (abs(ans) - count_onedge(P)) / 2 + 1;
}
