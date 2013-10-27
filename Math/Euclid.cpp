// $\gcd(a, b) = \gcd(b, a\bmod b)$
// $O(\lg b)$
int Euclid(int a, int b) {
	return b!=0 ? Euclid(b, a%b) : a;
}

// calculate such $(d, x, y)$ that $d = \gcd(a, b) = ax+by$
struct EuclidTriple {
	int d, x, y;
};
// $O(\lg b)$
EuclidTriple Euclid_extended(int a, int b) {
	if (b == 0) {
		EuclidTriple res = {a, 1, 0};
		return res;
	}
	EuclidTriple tmp = Euclid_extended(b, a%b);
	EuclidTriple res = {tmp.d, tmp.y, tmp.x - a / b * tmp.y};
	return res;
}
