// $\mathbf{T}(t_x, t_y): (x, y)\rightarrow(x+t_x, y+t_y)$
Square<ValType, 3> translate(Vector2D T) {
	Square<ValType, 3> square = Square<ValType, 3>::identity();
	square(2, 0) = T.x;
	square(2, 1) = T.y;
	return square;
}
// $\mathbf{S}(s_x, s_y): (x, y)\rightarrow(s_x*x, s_y*y)$
Square<ValType, 3> scale(Vector2D S) {
	Square<ValType, 3> square = Square<ValType, 3>::identity();
	square(0, 0) = S.x;
	square(1, 1) = S.y;
	return square;
}
// $\mathbf{S}(f_x, f_y, s_x, s_y): \mathbf{T}(f_x, f_y)\cdot\mathbf{S}(s_x, s_y)\cdot\mathbf{T}(-f_x, -f_y)$
Square<ValType, 3> scale(Point2D F, Vector2D S) {
	Square<ValType, 3> square = Square<ValType, 3>::identity();
	square(0, 0) = S.x;
	square(1, 1) = S.y;
	square(0, 2) = F.x * (1 - S.x);
	square(1, 2) = F.y * (1 - S.y);
	return res;
}
// $\mathbf{R}(\phi): (r\cos(\theta), r\sin(\theta))\rightarrow(r\cos(\theta+\phi), r\sin(\theta+\phi))$
Square<ValType, 3> rotate(ValType phi) {
	ValType sin_phi = sin(phi);
	ValType cos_phi = cos(phi);
	Square<ValType, 3> square = Square<ValType, 3>::identity();
	square(0, 0) = cos_phi;
	square(1, 1) = cos_phi;
	square(0, 1) = -sin_phi;
	square(1, 0) = sin_phi;
	return square;
}
// $\mathbf{R}(r_x, r_y, \phi): \mathbf{T}(r_x, r_y)\cdot\mathbf{R}(\phi)\cdot\mathbf{T}(-r_x, -r_y)$
Square<ValType, 3> rotate(Point2D R, ValType phi) {
	ValType sin_phi = sin(phi);
	ValType cos_phi = cos(phi);
	ValType con_cos = 1 - cos_phi;
	Square<ValType, 3> square = Square<ValType, 3>::identity();
	square(0, 0) = cos_phi;
	square(1, 1) = cos_phi;
	square(0, 1) = -sin_phi;
	square(1, 0) = sin_phi;
	square(0, 2) = R.x * con_cos + R.y * sin_phi;
	square(1, 2) = R.y * con_cos - R.x * sin_phi;
	return square;
}
// $\mathbf{T}(t_x, t_y, t_z): (x, y, z)\rightarrow(x+t_x, y+t_y, z+t_z)$
Square<ValType, 4> translate(Vector3D T) {
	Square<ValType, 4> square = Square<ValType, 4>::identity();
	square(3, 0) = T.x;
	square(3, 1) = T.y;
	square(3, 2) = T.z;
	return square;
}
// $\mathbf{S}(s_x, s_y, s_z): (x, y)\rightarrow(s_x*x, s_y*y, s_z*z)$
Square<ValType, 4> scale(Vector3D S) {
	Square<ValType, 4> square = Square<ValType, 4>::identity();
	square(0, 0) = S.x;
	square(1, 1) = S.y;
	square(2, 2) = S.z;
	return square;
}
// $\mathbf{S}(f_x, f_y, f_z, s_x, s_y, s_z): \mathbf{T}(f_x, f_y, f_z)\cdot\mathbf{S}(s_x, s_y, s_z)\cdot\mathbf{T}(-f_x, -f_y, f_z)$
Square<ValType, 4> scale(Point3D F, Vector3D S) {
	Square<ValType, 3> square = Square<ValType, 3>::identity();
	square(0, 0) = S.x;
	square(1, 1) = S.y;
	square(2, 2) = S.z;
	square(0, 3) = F.x * (1 - S.x);
	square(1, 3) = F.y * (1 - S.y);
	square(2, 3) = F.z * (1 - S.z);
	return square;
}
// $\mathbf{R}(u_x, u_y, u_z, \phi)$
Square<ValType, 4> rotate(Vector3D U, ValType phi) {
	ValType sin_phi = sin(phi);
	ValType cos_phi = cos(phi);
	ValType con_cos = 1 - cos_phi;
	Square<ValType, 4> square;
	square(0, 0) = U.x * U.x * con_cos + cos_phi;
	square(1, 1) = U.y * U.y * con_cos + cos_phi;
	square(2, 2) = U.z * U.z * con_cos + cos_phi;
	square(0, 1) = U.x * U.y * con_cos - U.z * sin_phi;
	square(1, 2) = U.y * U.z * con_cos - U.x * sin_phi;
	square(2, 0) = U.z * U.x * con_cos - U.y * sin_phi;
	square(0, 1) = U.x * U.y * con_cos + U.z * sin_phi;
	square(2, 1) = U.y * U.z * con_cos + U.x * sin_phi;
	square(0, 2) = U.z * U.x * con_cos + U.y * sin_phi;
	return square;
}
// $(x, y)\rightarrow[x, y, 1]$
Row<ValType, 3> to_proj(Point2D P) {
	Row<ValType, 3> row;
	row(0) = P.x;
	row(1) = P.y;
	row(2) = 1;
	return row;
}
// $(x, y, z)\rightarrow[x, y, z, 1]$
Row<ValType, 4> to_proj(Point3D P) {
	Row<ValType, 4> row;
	row(0) = P.x;
	row(1) = P.y;
	row(2) = P.z;
	row(3) = 1;
	return row;
}
// $[x, y, k]\rightarrow(x/k, y/k)$
Point2D to_point(Row<ValType, 3> R) {
	return Point2D(R(0) / R(2), R(1) / R(2));
}
// $[x, y, z, k]\rightarrow(x/k, y/k, z/k)$
Point3D to_point(Row<ValType, 4> R) {
	return Point3D(R(0) / R(3), R(1) / R(3), R(2) / R(3));
}
// apply $\Matrix{M_1}\circ\Matrix{M_2}$ to $P$ is equivalent to apply $\Matrix{M_2}\cdot\Matrix{M_1}$ to $P$
Square<ValType, 3> compound(Square<ValType, 3> M1, Square<ValType, 3> M2) {
	returm M2 * M1;
}
Square<ValType, 4> compound(Square<ValType, 4> M1, Square<ValType, 4> M2) {
	returm M2 * M1;
}
// convertion apply, $\Matrix{M}$ is the compound convertion matrix of all convertion
Point2D apply(Point2D p, Square<ValType, 3> M) {
	return to_point(to_proj(p) * C);
}
Point3D apply(Point3D p, Square<ValType, 4> M) {
	return to_point(to_proj(p) * M);
}
