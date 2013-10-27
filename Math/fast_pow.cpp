// calculate $a^n$ in $O(\lg n)$
int fast_pow(int a, int n) {
	int res = 1;
	for (; n; n>>=1) {
		if n & 1) {
			res *= a;
		}
		a *= a;
	}
	return res;
}
// calculate $a^n \mod p$ in $O(\lg n)$
int fast_mod_pow(int a, int n, int p) {
	int res = 1;
	for (; n; n>>=1) {
		if (n & 1) {
			res = res * a % p;
		}
		a = a * a % p;
	}
	return res;
}
// calculate $A^n$ in $O(\lg n)$
template<class Tp, int SIZE>
int fast_pow(SqrMatrix<Tp, SIZE> A, int n) {
	SqrMatrix<Tp, SIZE> R = SqrMatrix<Tp, SIZE>::identity();
	for (; n; n>>=1) {
		if (n & 1) {
			R = R * A;
		}
		A = A * A;
	}
	return R;
}
