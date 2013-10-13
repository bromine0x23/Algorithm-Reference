// calculate $a^n$ in $O(\lg n)$
int fast_pow(int a, int n) {
	int res = 1;
	for (; n != 0; n /= 2) {
		if (n % 2 == 1) {
			res *= a;
		}
		a *= a;
	}
	return res;
}
