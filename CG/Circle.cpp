// Circle:$\{P||\overrightarrow{PC}|=R\}$
struct Circle {
	Vector2D c;
	ValType r;
	Circle(void) : c(), r() { }
	Circle(Vector2D cc, ValType rr) : c(cc), r(rr) { }
	Circle(Circle cir) : c(cir.c), r(cir.r) { }
};
// Circumscribed circle
Circle smallest_circle(vector<Vector2D> & points) {
	int const SIZE = points.size();
	random_shuffle(points.begin(), points.end());
	Vector2D center = points[0];
	ValType r = ValType(); // 0
	for (int i=1; i<SIZE; ++i) {
        if (is_nsml(r, dist(points[i], c))) {
			continue;
        }
        c = points[i];
		r = ValType(); // 0
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
				c = Triangle2D(points[i], points[j], points[k]).circumcenter();
				r = (points[k] - c).norm();
			}
		}
	}
	return Circle(c, r);
}
// area of $C_1\cap C_2$
ValType area_intersection(Circle c1, Circle c2) {
	ValType distance = dist(c1.c, c2.c);
	if (is_nsml(distance, c1.r + c2.r)) {
		return 0.0;
	}
	ValType max_r = max_by_val(c1.r, c2.r);
	ValType min_r = min_by_val(c1.r, c2.r);
	if (is_nsml(max_r, min_r + distance)) {
		return PI * pow(min_r, 2.0);
	}
	ValType c1 = (distance * distance + max_r * max_r - min_r * min_r) * 0.5 / (distance * max_r);
	ValType c2 = (distance * distance + min_r * min_r - max_r * max_r) * 0.5 / (distance * min_r);
	ValType s1 = max_r * max_r * (acos(c1) - sin(acos(c1)) * c1);
	ValType s2 = min_r * min_r * (acos(c2) - sin(acos(c2)) * c1);
	return s1 + s2;
}
// area of $C_1\cap C_2$
ValType area_union(Circle c1, Circle c2) {
	ValType distance = dist(c1.c, c2.c);
	if (is_nsml(distance, b1.r + b2.r)) {
		return PI * (pow(b1.r, 2.0) + pow(b2.r, 2.0));
	}
	ValType max_r = max_by_val(c1.r, c2.r);
	ValType min_r = min_by_val(c1.r, c2.r);
	if (is_nsml(max_r, min_r + distance)) {
		return PI * pow(max_r, 2.0);
	}
	ValType h1 = (distance + (b1.r*b1.r - b2.r*b2.r) * (1.0 / distance)) * 0.5;
	ValType h2 = (distance - (b1.r*b1.r - b2.r*b2.r) * (1.0 / distance)) * 0.5;
	return PI * (
		(b1.r * pow(b1.r + h1, 2.0) - 1.0 / 3.0 * pow(b1.r + h1, 3.0))
		(b2.r * pow(b2.r + h2, 2.0) - 1.0 / 3.0 * pow(b2.r + h2, 3.0))
	);
}
