// $O(\lg b)$
int euclid(int a, int b) {
	return b!=0 ? euclid(b, a%b) : a;
}

// $O(\lg b)$, calculate such $(d, x, y)$ that $d = \gcd(a, b) = ax+by$
struct EuclidTriple {
	int d, x, y;
};
EuclidTriple euclid_extended(int a, int b) {
	if (b == 0) {
		EuclidTriple res = {a, 1, 0};
		return res;
	}
	EuclidTriple tmp = euclid_extended(b, a % b);
	EuclidTriple res = {tmp.d, tmp.y, tmp.x - a / b * tmp.y};
	return res;
}
