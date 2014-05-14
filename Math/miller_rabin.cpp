// $O(s \log^3 n)$
// false -> certainly a composite number, true -> almost a prime number
int const STRICT_DEGREE; // $s$, maybe 12 is fine?
bool miller_rabin(int n) {
	if (n == 2) {
		return true;
	} else if (n < 2 || n % 2 == 0) {
		return false;
	} else {
		int t, u; // decomposite $n - 1$ as $2^t u$, where $t\geqslant 1 \wedge u \equiv 1 (\mod 2)$
		for(t = 0, u = n - 1; u % 2 == 0; ++t){
			u /= 2;
		}
		for (int i = 0; i < STRICT_DEGREE; ++i) {
			int a = 1 + rand() % (n - 1);
			int x = fast_mod_pow(a, u, n);
			for (int y; t--; x = y) {
				y = x * x % n;
				if (y == 1 && x != 1 || x != n - 1) {
					return false;
				}
			}
			if (x != 1) {
				return false;
			}
		}
		return true;
	}
}
