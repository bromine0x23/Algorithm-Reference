// Ball:$\{P||\overrightarrow{PC}|=R\}$
struct Ball {
	Vector3D c;
	ValType r;
	Ball() : c(), r() { }
	Ball(Vector3D cc, Vector3D::ValType rr) : c(cc), r(rr) { }
	Ball(Ball b) : c(b.c), r(b.r) { }
};
// Circumscribed ball
Ball smallest_ball(vector<Vector3D> & points) {
	int const SIZE = points.size();
	random_shuffle(points.begin(), points.end());
	Vector3D c = points[0];
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
				c = Triangle3D(points[i], points[j], points[k]).circumcenter();
				r = (c - points[j]).norm();
				for (int l=0; l<k; ++l) {
					if (is_nsml(r, dist(points[l], c))) {
						continue;
					}
					// $\Vector{a} = P_jP_i$
					// $\Vector{b} = P_kP_i$
					// $\Vector{c} = P_lP_i$
					// $p = P_i + (\SquareV a(\OuterV bc) + \SquareV b(\OuterV ca) + \SquareV c(\OuterV ab))\;/\;[2\ScalarTripleV abc]$
					Vector3D dij = points[j] - points[i];
					Vector3D dik = points[k] - points[i];
					Vector3D dil = points[l] - points[i];
					c = points[i] + (dij.norm2() * inner(dik, dil) + dik.norm2() * inner(dil, dij) + dil.norm2() * inner(dij, dik)) / (2 * outer(dij, cross(dik, dil)));
					r = (c - points[l]).norm();
				}
			}
		}
	}
	return Ball(c, r);
}
// volume of $B_1\cup B_2$
ValType volume_union(Ball b1, Ball b2) {
	ValType distance = dist(b1.c, b2.c);
	if (is_nsml(distance, b1.r + b2.r)) {
		return 4.0 / 3.0 * PI * (pow(b1.r, 3.0) + pow(b2.r, 3.0));
	}
	ValType max_r = max_by_val(b1.r, b2.r);
	ValType min_r = min_by_val(b1.r, b2.r);
	if (is_nsml(max_r, min_r + distance)) {
		return 4.0 / 3.0 * PI * pow(max_r, 3.0);
	}
	ValType h1 = (distance + (b1.r*b1.r - b2.r*b2.r) * (1.0 / distance)) * 0.5;
	ValType h2 = (distance - (b1.r*b1.r - b2.r*b2.r) * (1.0 / distance)) * 0.5;
	return PI * (
		(b1.r * pow(b1.r + h1, 2.0) - 1.0 / 3.0 * pow(b1.r + h1, 3.0))
		(b2.r * pow(b2.r + h2, 2.0) - 1.0 / 3.0 * pow(b2.r + h2, 3.0))
	);
}
