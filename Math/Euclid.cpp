// $\gcd(a, b) = \gcd(b, a\bmod b)$
// $O(\lg b)$
int Euclid(int a, int b) {
	return b!=0 ? Euclid(b, a%b) : a;
}

// calculate such $(d, x, y)$ that $d = \gcd(a, b) = ax+by$
struct Triple {
	int x, y, z;
};
// $O(\lg b)$
Triple Euclid_extended(int a, int b) {
	if (b == 0) {
		Triple res = {a, 1, 0};
		return res;
	}
	Triple tmp = Euclid_extended(b, a%b);
	Triple res = {tmp.x, tmp.z, tmp.y - a / b * tmp.z};
	return res;
}
