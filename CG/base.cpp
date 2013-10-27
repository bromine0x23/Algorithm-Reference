typedef double ValType;
ValType EPSILON = 1E-9;
int sign(ValType x) {
	return x < -EPSILON ? -1 : x > EPSILON;
}
bool is_zero(ValType x) {
	return sign(x) == 0;
}
bool is_pos(ValType x) {
	return sign(x) == 1;
}
bool is_npos(ValType x) {
	return sign(x) != 1;
}
bool is_neg(ValType x) {
	return sign(x) == -1;
}
bool is_nneg(ValType x) {
	return sign(x) != -1;
}
bool is_grt(ValType x, ValType y) {
	return is_pos(x - y);
}
bool is_ngrt(ValType x, ValType y) {
	return is_npos(x - y);
}
bool is_sml(ValType x, ValType y) {
	return is_neg(x - y);
}
bool is_nsml(ValType x, ValType y) {
	return is_nneg(x - y);
}
// Segment:$\overline{P_1 P_2}$
struct Segment {
	Point2D p1, p2;
};
