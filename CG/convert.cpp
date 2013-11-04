// $\mathbf{T}(t_x, t_y): (x, y)\rightarrow(x+t_x, y+t_y)$
SqrMatrix<ValType, 3> translate(Vector2D T) {
	SqrMatrix<ValType, 3> res = SqrMatrix<ValType, 3>::identity();
	res(2, 0) = T.x; res(2, 1) = T.y;
	return res;
}
// $\mathbf{S}(s_x, s_y): (x, y)\rightarrow(s_x*x, s_y*y)$
SqrMatrix<ValType, 3> scale(Vector2D S) {
	SqrMatrix<ValType, 3> res = SqrMatrix<ValType, 3>::identity();
	res(0, 0) = S.x; res(1, 1) = S.y;
	return res;
}
// $\mathbf{S}(f_x, f_y, s_x, s_y): \mathbf{T}(f_x, f_y)\cdot\mathbf{S}(s_x, s_y)\cdot\mathbf{T}(-f_x, -f_y)$
SqrMatrix<ValType, 3> scale(Point2D F, Vector2D S) {
	SqrMatrix<ValType, 3> res = SqrMatrix<ValType, 3>::identity();
	res(0, 0) = S.x;             res(1, 1) = S.y;
	res(0, 2) = F.x * (1 - S.x); res(1, 2) = F.y * (1 - S.y);
	return res;
}
// $\mathbf{R}(\phi): (r\cos(\theta), r\sin(\theta))\rightarrow(r\cos(\theta+\phi), r\sin(\theta+\phi))$
SqrMatrix<ValType, 3> rotate(ValType phi) {
	SqrMatrix<ValType, 3> res = SqrMatrix<ValType, 3>::identity();
	ValType sin_phi = sin(phi), cos_phi = cos(phi);
	res(0, 0) =  cos_phi; res(1, 1) = cos_phi;
	res(0, 1) = -sin_phi; res(1, 0) = sin_phi;
	return res;
}
// $\mathbf{R}(r_x, r_y, \phi): \mathbf{T}(r_x, r_y)\cdot\mathbf{R}(\phi)\cdot\mathbf{T}(-r_x, -r_y)$
SqrMatrix<ValType, 3> rotate(Point2D R, ValType phi) {
	SqrMatrix<ValType, 3> res = SqrMatrix<ValType, 3>::identity();
	ValType sin_phi = sin(phi), cos_phi = cos(phi);
	ValType con_cos = 1 - cos_phi;
	res(0, 0) =  cos_phi; res(1, 1) = cos_phi;
	res(0, 1) = -sin_phi; res(1, 0) = sin_phi;
	res(0, 2) = R.x * con_cos + R.y * sin_phi;
	res(1, 2) = R.y * con_cos - R.x * sin_phi;
	return res;
}
// $\mathbf{T}(t_x, t_y, t_z): (x, y, z)\rightarrow(x+t_x, y+t_y, z+t_z)$
SqrMatrix<ValType, 4> translate(Vector3D T) {
	SqrMatrix<ValType, 4> res = SqrMatrix<ValType, 4>::identity();
	res(3, 0) = T.x; res(3, 1) = T.y; res(3, 2) = T.z;
	return res;
}
// $\mathbf{S}(s_x, s_y, s_z): (x, y)\rightarrow(s_x*x, s_y*y, s_z*z)$
SqrMatrix<ValType, 4> scale(Vector3D S) {
	SqrMatrix<ValType, 4> res = SqrMatrix<ValType, 4>::identity();
	res(0, 0) = S.x; res(1, 1) = S.y; res(2, 2) = S.z;
	return res;
}
// $\mathbf{S}(f_x, f_y, f_z, s_x, s_y, s_z): \mathbf{T}(f_x, f_y, f_z)\cdot\mathbf{S}(s_x, s_y, s_z)\cdot\mathbf{T}(-f_x, -f_y, f_z)$
SqrMatrix<ValType, 4> scale(Point3D F, Vector3D S) {
	SqrMatrix<ValType, 3> res = SqrMatrix<ValType, 3>::identity();
	res(0, 0) = S.x;             res(1, 1) = S.y;             res(2, 2) = S.z;
	res(0, 3) = F.x * (1 - S.x); res(1, 3) = F.y * (1 - S.y); res(2, 3) = F.z * (1 - S.z);
	return res;
}
// $\mathbf{R}(u_x, u_y, u_z, \phi)$
SqrMatrix<ValType, 4> rotate(Vector3D U, ValType phi) {
	SqrMatrix<ValType, 4> res;
	ValType sin_phi = sin(phi), cos_phi = cos(phi);
	ValType con_cos = 1 - cos_phi;
	res(0, 0) = U.x * U.x * con_cos + cos_phi;
	res(1, 1) = U.y * U.y * con_cos + cos_phi;
	res(2, 2) = U.z * U.z * con_cos + cos_phi;
	res(0, 1) = U.x * U.y * con_cos - U.z * sin_phi;
	res(1, 2) = U.y * U.z * con_cos - U.x * sin_phi;
	res(2, 0) = U.z * U.x * con_cos - U.y * sin_phi;
	res(0, 1) = U.x * U.y * con_cos + U.z * sin_phi;
	res(2, 1) = U.y * U.z * con_cos + U.x * sin_phi;
	res(0, 2) = U.z * U.x * con_cos + U.y * sin_phi;
	return res;
}
// $(x, y)\rightarrow[x, y, 1]$
Row<ValType, 3> to_proj(Point2D P) {
	Row res; res(0) = P.x; res(1) = P.y; res(2) = 1;
	return res;
}
// $(x, y, z)\rightarrow[x, y, z, 1]$
Row<ValType, 4> to_proj(Point3D P) {
	Row res; res(0) = P.x; res(1) = P.y; res(3) = P.z; res(3) = 1;
	return res;
}
// $[x, y, k]\rightarrow(x/k, y/k)$
Point2D to_point(Row<ValType, 3> R) {
	return Point(R(0) / R(2), R(1) / R(2));
}
// $[x, y, z, k]\rightarrow(x/k, y/k, z/k)$
Point3D to_point(Row<ValType, 4> R) {
	return Point(R(0) / R(3), R(1) / R(3), R(2) / R(3));
}
// apply $\Matrix{M_1}\circ\Matrix{M_2}$ to $P$ is equivalent to apply $\Matrix{M_2}\cdot\Matrix{M_1}$ to $P$
SqrMatrix<ValType, 3> compound(SqrMatrix<ValType, 3> M1, SqrMatrix<ValType, 3> M2) {
	returm M2 * M1;
}
SqrMatrix<ValType, 4> compound(SqrMatrix<ValType, 4> M1, SqrMatrix<ValType, 4> M2) {
	returm M2 * M1;
}
// convertion apply, $\Matrix{M}$ is the compound convertion matrix of all convertion
Point2D apply(Point2D p, SqrMatrix<ValType, 3> M) {
	return to_point(to_proj(p) * C);
}
Point3D apply(Point3D p, SqrMatrix<ValType, 4> M) {
	return to_point(to_proj(p) * M);
}
