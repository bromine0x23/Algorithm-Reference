// $(x, y) \rightarrow (x+d_x, y+d_y)$
SqrMatrix<ValType, 3> translate(Vector2D d) {
	SqrMatrix<ValType, 3> res = SqrMatrix<ValType, 3>::identity();
	res(2, 0) = d.x; res(2, 1) = d.y;
	return res;
}
// $(x, y, z) \rightarrow (x+d_x, y+d_y, z+d_z)$
SqrMatrix<ValType, 4> translate(Vector3D d) {
	SqrMatrix<ValType, 4> res = SqrMatrix<ValType, 4>::identity();
	res(3, 0) = d.x; res(3, 1) = d.y; res(3, 2) = d.z;
	return res;
}
// $(x, y) \rightarrow (x+s_x, y+s_y)$
SqrMatrix<ValType, 3> scale(Vector2D s) {
	SqrMatrix<ValType, 3> res = SqrMatrix<ValType, 3>::identity();
	res(0, 0) = s.x; res(1, 1) = s.y;
	return res;
}
// $(x, y, z) \rightarrow (x+s_x, y+s_y, z+s_z)$
SqrMatrix<ValType, 4> scale(Vector3D s) {
	SqrMatrix<ValType, 4> res = SqrMatrix<ValType, 4>::identity();
	res(0, 0) = s.x; res(1, 1) = s.y; res(2, 2) = s.z;
	return res;
}
// rotate $\theta$ clockwis about $(0, 0)$
SqrMatrix<ValType, 3> rotate(ValType theta) {
	ValType sin_val = sin(theta);
	ValType cos_val = cos(theta);
	SqrMatrix<ValType, 3> res = SqrMatrix<ValType, 3>::identity();
	res(1, 1) = res(0, 0) = cos_val;
	res(0, 1) = sin_val;
	res(1, 0) = -sin_val;
	return res;
}
// rotate $\theta$ clockwis about $(0, 0, 0)$ with direction $d$
SqrMatrix<ValType, 4> rotate(Vector3D d, ValType theta) {
	SqrMatrix<ValType, 4> res = SqrMatrix<ValType, 4>::identity();
	ValType sin_val = sin(theta);
	ValType cos_val = cos(theta);
	ValType con_cos = 1 - cos_val;
	res(0, 0) = con_cos * d.x * d.x + cos_val;
	res(1, 1) = con_cos * d.y * d.y + cos_val;
	res(2, 2) = con_cos * d.z * d.z + cos_val;
	res(0, 1) = con_cos * d.x * d.y - sin_val * d.z;
	res(0, 2) = con_cos * d.x * d.z + sin_val * d.y;
	res(1, 2) = con_cos * d.y * d.z - sin_val * d.x;
	res(1, 0) = con_cos * d.y * d.x + sin_val * d.z;
	res(2, 0) = con_cos * d.z * d.x - sin_val * d.y;
	res(2, 1) = con_cos * d.z * d.y + sin_val * d.x;
	return res;
}
// $(x, y)\rightarrow [x, y, 1]$
Row<ValType, 3> to_proj(Point2D P) {
	Row res; res(0) = P.x; res(1) = P.y; res(2) = 1;
	return res;
}
// $(x, y, z)\rightarrow [x, y, z, 1]$
Row<ValType, 4> to_proj(Point3D P) {
	Row res; res(0) = P.x; res(1) = P.y; res(3) = P.z; res(3) = 1;
	return res;
}
// $[x, y, k] \rightarrow (x/k, y/k)$
Point2D to_point(Row<ValType, 3> R) {
	ValType k = R(2);
	return Point(R(0) / k, R(1) / k);
}
// $[x, y, z, k] \rightarrow (x/k, y/k, z/k)$
Point3D to_point(Row<ValType, 4> R) {
	ValType k = R(3);
	return Point(R(0) / k, R(1) / k, R(2) / k);
}
// convertion apply, C is the product of translate, scale, rotate matrix
Point2D apply(Point2D p, SqrMatrix<ValType, 3> C) {
	return to_point(to_proj(p) * C);
}
Point3D apply(Point3D p, SqrMatrix<ValType, 4> C) {
	return to_point(to_proj(p) * C);
}
