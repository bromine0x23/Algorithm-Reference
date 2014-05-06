// $O(\lg n)$, calculate $a^n$
int fast_pow(int a, int n) {
	int res = 1;
	for (; n; n /= 2) {
		if (n % 2 == 1) {
			res *= a;
		}
		a *= a;
	}
	return res;
}
// $O(\lg n)$, calculate $a^n \mod p$
int fast_mod_pow(int a, int n, int p) {
	int res = 1;
	for (; n; n /= 2) {
		if (n % 2 == 1) {
			res = res * a % p;
		}
		a = a * a % p;
	}
	return res;
}
// $O(\lg n)$, calculate $A^n$
template<class Tp, int SIZE>
int fast_pow(SqrMatrix<Tp, SIZE> A, int n) {
	SqrMatrix<Tp, SIZE> R = SqrMatrix<Tp, SIZE>::identity();
	for (; n; n /= 2) {
		if (n % 2 == 1) {
			R = R * A;
		}
		A = A * A;
	}
	return R;
}
