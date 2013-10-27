// 2D Vector or Point:$(x, y)$
struct Vector2D {
	ValType x, y;
	Vector2D() : x(), y() { }
	Vector2D(ValType xx, ValType yy) : x(xx), y(yy) { }
	Vector2D(Vector2D v) : x(v.x), y(v.y) { }
	// $\NormSquare{P}$
	ValType norm2() const {
		return x*x + y*y;
	}
	// $\Norm{P}$
	ValType norm() const {
		return sqrt(norm2());
	}
	// $\Vector{P}\;/\;\Norm{P}$
	Vector2D unit() {
		ValType rate = 1.0 / norm();
		return Vector2D(rate * x, rate * y);
	}
};
typedef Vector2D Point2D;
// $\Vector{V_1} + \Vector{V_2}$
Vector2D operator+(Vector2D v1, Vector2D v2) {
	return Vector2D(v1.x + v2.x, v1.y + v2.y);
}
// $\Vector{V_1} - \Vector{V_2}$
Vector2D operator-(Vector2D v1, Vector2D v2) {
	return Vector2D(v1.x - v2.x, v1.y - v2.y);
}
// $k\Vector{V}$
Vector2D operator*(ValType k, Vector2D p) {
	return Vector2D(k * p.x, k * p.y);
}
Vector2D operator*(Vector2D p, ValType k) {
	return Vector2D(k * p.x, k * p.y);
}
// $\frac{1}{k}\Vector{V}$
Vector2D operator/(Vector2D p, ValType k) {
	return Vector2D(p.x / k, p.y / k);
}
// $|P_1 P_2|$
ValType dist(Point2D p1, Point2D p2) {
	return (p1 - p2).norm();
}
// $\InnerV{V_1}{V_2}$
ValType inner(Vector2D v1, Vector2D v2) {
	return v1.x * v2.x + v1.y * v2.y;
}
// $\OuterV{V_1}{V_2}$
ValType outer(Vector2D v1, Vector2D v2) {
	return v1.x * v2.y - v1.y * v2.x;
}
// $\VectorTripleV{V_1}{V_2}{V_3}$
Vector2D vector_triple(Vector2D v1, Vector2D v2, Vector2D v3) {
	return v2 * inner(v1, v3) - v3 * inner(v1, v2);
}
// $\NormSquare{\OuterV {V_1}{V_2}}$
Vector2D outer_norm2(Vector2D v1, Vector2D v2) {
	return v1.norm2() * v2.norm2() - inner(v1, v2).norm2();
}
// $\Norm{\OuterV {V_1}{V_2}}$
Vector2D outer_norm(Vector2D v1, Vector2D v2) {
	return sqrt(outer_norm2(v1, v2));
}
Point2D foot(Point2D p, Point2D orig, Vector2D dire) {
	return orig - dire.norm2() * (1.0 / inner(p-orig, dire)) * dire;
}
Point2D rotate(Point2D p, Point2D orig, Vector2D dire, Vector2D::ValType ang) {
	Point2D root = foot(p, orig, dire);
	Point2D u = p - root;
	Point2D v = r * dire.unit();
	return root + u * cos(ang) - v * sin(ang);
}
