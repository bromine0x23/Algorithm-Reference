// 3D Vector or Point:$(x, y, z)$
struct Vector2D {
	ValType x, y, z;
	Vector3D(void) : x(), y(), z() { }
	Vector3D(ValType xx, ValType yy, ValType zz) : x(xx), y(yy), z(zz) { }
	Vector3D(Vector3D const & v) : x(v.x), y(v.y) { }
	// $\NormSquare{P}$
	ValType norm2() const {
		return x*x + y*y + z*z;
	}
	// $\Norm{P}$
	ValType norm() const {
		return sqrt(norm2());
	}
	// $\Vector{P}\;/\;\Norm{P}$
	Vector3D unit() {
		ValType rate = 1.0 / norm();
		return Vector2D(rate * x, rate * y, rate * z);
	}
};
typedef Vector3D Point3D;
// $\Vector{V_1} + \Vector{V_2}$
Vector3D operator+(Vector3D const & v1, Vector3D const & v2) {
	return Vector3D(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z);
}
// $\Vector{V_1} - \Vector{V_2}$
Vector3D operator-(Vector3D const & v1, Vector3D const & v2) {
	return Vector3D(v1.x - v2.x, v1.y - v2.y, v1.z - v2.z);
}
// $k\Vector{V}$
Vector3D operator*(ValType const & k, Vector3D const & p) {
	return Vector3D(k * p.x, k * p.y, k * p.z);
}
Vector3D operator*(Vector3D const & p, ValType const & k) {
	return Vector3D(k * p.x, k * p.y, k * p.z);
}
// $\frac{1}{k}\Vector{V}$
Vector3D operator/(Vector3D const & p, ValType const & k) {
	return Vector3D(p.x / k, p.y / k, p.z / k);
}
// $|P_1 P_2|$
ValType dist(Point3D const & p1, Point3D const & p2) {
	return (p1-p2).norm();
}
// $\InnerV{V_1}{V_2}$
ValType inner(Vector3D const & v1, Vector3D const & v2) {
	return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
}
// $\OuterV{V_1}{V_2}$
Vector3D outer(Vector3D const & v1, Vector3D const & v2) {
	return Vector3D(v1.y * v2.z - v1.z * v2.y, v1.z * v2.x - v1.x * v2.z, v1.x * v2.y - v1.y * v2.x)
}
// $\VectorTripleV{V_1}{V_2}{V_3}$
Vector3D vector_triple(Vector3D const & v1, Vector3D const & v2, Vector3D const & v3) {
	return v1.inner(v2.inner(v3));
}
// $\NormSquare{\OuterV {V_1}{V_2}}$
Vector2D outer_norm2(Vector3D const & v1, Vector3D const & v2) {
	return inner(v1, v2).norm2();
}
// $\Norm{\OuterV {V_1}{V_2}}$
Vector2D outer_norm(Vector3D const & v1, Vector3D const & v2) {
	return sqrt(outer_norm2(v1, v2));
}
Point3D foot(Point3D p, Point3D orig, Vector3D dire) {
	return orig - dire.norm2() * (1.0 / inner(p-orig, dire)) * dire;
}
Point3D rotate(Point3D p, Point3D orig, Vector3D dire, ValType ang) {
	Point3D root = foot(p, orig, dire);
	Point3D u = p - root;
	Point3D v = r * dire.unit();
	return root + u * cos(ang) - v * sin(ang);
}
