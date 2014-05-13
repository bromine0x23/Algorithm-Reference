// calculate $C_n^k \mod p$
// $C_n^k \equiv \prod C_{n_i}^{k_i} \mod p$
// $n = \sum n_ip^i$
// $k = \sum k_ip^i$
int const FACTORIAL[]; // $FACTORIAL_n=n!$, i.e. $\{1, 1, 2, 6, 24, 120, 720, \ldots\}$
int Lucas_Combine(int n, int k, int p) {
	if (n < k) {
		return 0;
	} else {
		return FACTORIAL[n] * fast_mod_pow(FACTORIAL[k] * FACTORIAL[n - k], p-2, p) % p;
	}
}
int Lucas(int n, int k, int p) {
	if (k == 0) {
		return 1;
	} else {
		return (Lucas_Combine(n % p, k % p, p) * Lucas(n / p, k / p, p)) % p;
	}
}
