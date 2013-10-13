int sign(double x) {
	return x < -EPSILON ? -1 : x > EPSILON;
}
// Segment:$\overline{P_1 P_2}$
struct Segment {
	Point2D p1, p2;
};
// Circle:$\{P||\overrightarrow{PC}|=R\}$
struct Circle {
	typedef Point2D::ValType ValType;
	Point2D c;
	ValType r;

	Circle(void) : c(), r() { }
	Circle(Point const & cc, Point::ValType rr) : c(cc), r(rr) { }
	Circle(Circle const & cir) : center(cir.c), radius(cir.r) { }
};
/*
外接圆

*/
Circle circumcircle(Point2D const & p1, Point2D const & p2, Point2D const & p3) {
	Vector2D a = p2 - p1;
	Vector2D b = p3 - p1;
	Vector2D t1 = a.norm2() * b - b.norm2() * a;
	Vector2D t2 = t1.dot(b) * a - t1.dot(a) * b;
	Vector2D::ValType t3 = a.norm2() * b.norm2() - sqr(a.dot(b));
	Vector2D  c = p1 + t2 / (2 * t3);
	Vector2D::ValType r = (p1 - c).norm();
	return Circle(c, r);
}
