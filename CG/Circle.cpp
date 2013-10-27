// Circle:$\{P||\overrightarrow{PC}|=R\}$
struct Circle {
	typedef Vector2D::ValType ValType;
	Vector2D c;
	ValType r;
	Circle(void) : c(), r() { }
	Circle(Vector2D cc, Vector2D::ValType rr) : c(cc), r(rr) { }
	Circle(Circle cir) : c(cir.c), r(cir.r) { }
};
// Circumscribed circle
Circle circumcircle(Point2D p1, Point2D p2, Point2D p3) {
	Vector2D a = p2 - p1;
	Vector2D b = p3 - p1;
	Vector2D t1 = a.norm2() * b - b.norm2() * a;
	Vector2D t2 = t1.dot(b) * a - t1.dot(a) * b;
	Vector2D::ValType t3 = a.norm2() * b.norm2() - sqr(a.dot(b));
	Vector2D  c = p1 + t2 / (2 * t3);
	Vector2D::ValType r = (p1 - c).norm();
	return Circle(c, r);
}
// Circumscribed circle
Circle smallest_circle(vector<Vector2D> & points) {
	int const SIZE = points.size();
	random_shuffle(points.begin(), points.end());
	Vector2D center = points[0];
	Vector2D::ValType r = Vector2D::ValType(); // 0
	for (int i=1; i<SIZE; ++i) {
        if (is_nsml(r, dist(points[i], c))) {
			continue;
        }
        c = points[i];
		r = Vector2D::ValType(); // 0
		for (int j=0; j<i; ++j) {
			if (is_nsml(r, dist(points[j], c))) {
				continue;
			}
			c = (points[i] + points[j]) / 2;
			r = (c - points[j]).norm();
			for (int k=0; k<j; ++k) {
				if (is_nsml(r, dist(points[k], c))) {
					continue;
				}
				// $\Vector{a} = P_jP_i$
				// $\Vector{b} = P_kP_i$
				// $p = P_i + \Outer{(\NormSquareV{a}\Vector{b}-\NormSquareV{b}\Vector{a})}{(\OuterV ab)}\;/\;2\NormSquareV{\OuterV ab}$
				Vector2D dij = points[j] - points[i];
				Vector2D dik = points[k] - points[i];
				c = points[i] + vector_triple((dij.norm2() * dik - dik.norm2() * dij), dij, dik) / (2 * outer_norm2(dij, dik));
				r = (points[k] - c).norm();
			}
		}
	}
	return Circle(c, r);
}
Circle::ValType volume_union(Circle c1, Circle c2) {
	Circle::ValType distance = dist(c1.c, c2.c);
	if (is_nsml(distance, c1.r + c2.r)) {
		return 0.0;
	}
	Circle::ValType max_r = max_by_val(c1.r, c2.r);
	Circle::ValType min_r = min_by_val(c1.r, c2.r);
	if (is_nsml(max_r, min_r + distance)) {
		return PI * pow(max_r, 2.0);
	}
	Circle::ValType c1 = (distance * distance + max_r * max_r - min_r * min_r) * 0.5 / (distance * max_r);
	Circle::ValType c2 = (distance * distance + min_r * min_r - max_r * max_r) * 0.5 / (distance * min_r);
	Circle::ValType s1 = max_r * max_r * (acos(c1) - sin(acos(c1)) * c1);
	Circle::ValType s2 = min_r * min_r * (acos(c2) - sin(acos(c2)) * c1);
	return s1 + s2;
}
