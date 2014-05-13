double RotatingCalipers(vector<Point> & points) {
	int const n = points.size();
	vector<int> C = Graham(points);
	C.push_back(C[0]);

	double ans = 0;
	int q = 1;
	for (int p = 0; p < n; ++p) {
		while (cross(C[p], C[p + 1], C[q + 1]) > cross(C[p], C[p + 1], C[q])) {
			q = (q + 1) % n;
		}
		update_maximum(ans, update_maximum(dist(C[p], C[q]), dist(C[p + 1], C[q + 1])));
	}
	return ans;
}
