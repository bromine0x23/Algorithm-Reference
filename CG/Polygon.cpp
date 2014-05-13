// $A = \frac{1}{2}\sum(P_k \times P_{k+1})$
ValType area(std::vector<Point2D> & P) {
	ValType ret = outer(P.back(), P.front());
	for (int i = 1; i < P.size(); ++i) {
		ret += outer(P[i-1], P[i]);
	}
	return ret / 2.0;
}
// $C = \frac{1}{6}\sum(P_k \times P_{k+1})(P_k+P_{k+1})$
Point2D barycenter(std::vector<Point2D> & P) {
	Point2D c = outer(P.back(), P.front()) * (P.front() + P.back());
	for (int i = 1; i < P.size(); ++i) {
		c += outer(P[i-1], P[i]) * (P[i-1] + P[i]);
	}
}
