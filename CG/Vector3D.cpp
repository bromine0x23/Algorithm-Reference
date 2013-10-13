// 3D Vecotr or Point:$(x, y, z)$
struct Vector2D {
	typedef double ValType;
	ValType x, y, z;
	Vector3D(void) : x(), y(), z() { }
	Vector3D(ValType xx, ValType yy, ValType zz) : x(xx), y(yy), z(zz) { }
	Vector3D(Vector3D const & v) : x(v.x), y(v.y) { }
	// ${|\overrightarrow{P}|}^2$
	ValType norm2() const {
		return x*x + y*y + z*z;
	}
	// ${|\overrightarrow{P}|}$
	ValType norm() const {
		return sqrt(norm2());
	}
	// $\overrightarrow{V_1} \cdot \overrightarrow{V_2}$
	Vector3D::ValType dot(Vector3D const & v2) const {
		return x * v2.x + y * v2.y + z * v2.z;
	}
	// $\overrightarrow{V_1} \times \overrightarrow{V_2}$
	Vector3D cross(Vector3D const & v2) const {
		return Vector3D(y * v2.z - z * v2.y, z * v2.x - x * v2.z, x * v2.y - y * v2.x)
	}
};
typedef Vector3D Point3D;
// $\overrightarrow{V_1} + \overrightarrow{V_2}$
Vector3D operator+(Vector3D const & v1, Vector3D const & v2) {
	return Vector3D(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z);
}
// $\overrightarrow{V_1} - \overrightarrow{V_2}$
Vector3D operator-(Vector3D const & v1, Vector3D const & v2) {
	return Vector3D(v1.x - v2.x, v1.y - v2.y, v1.z - v2.z);
}
// $k\overrightarrow{V}$
Vector3D operator*(Vector3D::ValType const & k, Vector3D const & p) {
	return Vector3D(k * p.x, k * p.y, k * p.z);
}
// $\frac{\overrightarrow{V}}{k}$
Vector3D operator/(Vector3D const & p, Vector3D::ValType const & k) {
	return Vector3D(p.x / k, p.y / k, p.z / k);
}
// $|P_1 P_2|$
Vector3D::ValType dist(Point3D const & p1, Point3D const & p2)
	return (p1-p2).norm();
}
