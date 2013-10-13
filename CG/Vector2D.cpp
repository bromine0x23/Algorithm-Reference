// 2D Vecotr or Point:$(x, y)$
struct Vector2D {
	typedef double ValType;
	ValType x, y;
	Vector2D(void) : x(), y() { }
	Vector2D(ValType xx, ValType yy) : x(xx), y(yy) { }
	Vector2D(Vector2D const & v) : x(v.x), y(v.y) { }
	// ${|\overrightarrow{P}|}^2$
	ValType norm2() const {
		return x*x + y*y;
	}
	// ${|\overrightarrow{P}|}$
	ValType norm() const {
		return sqrt(norm2());
	}
	// $\overrightarrow{V_1} \cdot \overrightarrow{V_2}$
	Vector2D::ValType dot(Vector2D const & v2) const {
		return x * v2.x + y * v2.y;
	}
	// $\overrightarrow{V_1} \times \overrightarrow{V_2}$
	Vector2D::ValType cross(Vector2D const & v2) const {
		return x * v2.y - y * v2.x;
	}
};
typedef Vector2D Point2D;
// $\overrightarrow{V_1} + \overrightarrow{V_2}$
Vector2D operator+(Vector2D const & v1, Vector2D const & v2) {
	return Vector2D(v1.x + v2.x, v1.y + v2.y);
}
// $\overrightarrow{V_1} - \overrightarrow{V_2}$
Vector2D operator-(Vector2D const & v1, Vector2D const & v2) {
	return Vector2D(v1.x - v2.x, v1.y - v2.y);
}
// $k\overrightarrow{V}$
Vector2D operator*(Vector2D::ValType const & k, Vector2D const & p) {
	return Vector2D(k * p.x, k * p.y);
}
// $\frac{\overrightarrow{V}}{k}$
Vector2D operator/(Vector2D const & p, Vector2D::ValType const & k) {
	return Vector2D(p.x / k, p.y / k);
}
// $|P_1 P_2|$
Vector2D::ValType dist(Point2D const & p1, Point2D const & p2)
	return (p1-p2).norm();
}
