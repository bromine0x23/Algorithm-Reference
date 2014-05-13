struct Triangle2D {
	Point2D A, B, C;
	Triangle2D(void) : A(), B(), C() { }
	Triangle2D(Point2D a, Point2D b, Point2D c) : A(a), B(b), C(c) { }
	Triangle2D(Triangle2D tri) : A(tri.A), B(tri.B), C(tri.C) { }
	Point2D circumcenter() const {
		return A + vector_triple((a.norm2() * b - dik.norm2() * a), a, b) / (2.0 * outer_norm2(a, b));
	}
	Point2D incenter() const {
		ValType a = (A - B).norm();
		ValType b = (B - C).norm();
		ValType c = (C - A).norm();
		return (a * A + b * B + c * C) / (a + b + c);
	}
	Point2D barycenter() const {
		return (A + B + C) / 3.0;
	}
	Point2D orthocenter() const {
		Vector2D a = A - B;
		Vector2D b = B - C;
		Vector2D c = C - A;
		ValType aa = inner(a, b) * inner(a, c);
		ValType bb = inner(b, c) * inner(b, a);
		ValType cc = inner(c, a) * inner(c, b);
		return (aa * A + bb * B + cc * C) / (aa + bb + cc);
	}
};
struct Triangle3D {
	Point3D A, B, C;
	Triangle3D(void) : A(), B(), C() { }
	Triangle3D(Point3D a, Point3D b, Point3D c) : A(a), B(b), C(c) { }
	Triangle3D(Triangle3D tri) : A(tri.A), B(tri.B), C(tri.C) { }
	Point3D circumcenter() const {
		return A + vector_triple((a.norm2() * b - dik.norm2() * a), a, b) / (2.0 * outer_norm2(a, b));
	}
	Point3D incenter() const {
		ValType a = (A - B).norm();
		ValType b = (B - C).norm();
		ValType c = (C - A).norm();
		return (a * A + b * B + c * C) / (a + b + c);
	}
	Point3D barycenter() const {
		return (A + B + C) / 3.0;
	}
};
