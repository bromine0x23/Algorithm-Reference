// $O(\lg n)$, calculate $a^n$
int fast_pow(int a, int n) {
	int result = 1;
	for (; n; n /= 2) {
		if (n % 2 == 1) {
			result *= a;
		}
		a *= a;
	}
	return result;
}
// $O(\lg n)$, calculate $a^n \mod p$
int fast_mod_pow(int a, int n, int p) {
	int result = 1;
	for (; n; n /= 2) {
		if (n % 2 == 1) {
			result = result * a % p;
		}
		a = a * a % p;
	}
	return result;
}
// $O(\lg n)$, calculate $A^n$
template<class value_type, int size>
int fast_pow(Square<value_type, size> A, int n) {
	Square<value_type, size> R = Square<value_type, size>::identity();
	for (; n; n /= 2) {
		if (n % 2 == 1) {
			R = R * A;
		}
		A = A * A;
	}
	return R;
}
