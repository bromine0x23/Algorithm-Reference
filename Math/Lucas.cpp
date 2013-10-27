// calculate $C_n^k \mod p$
// $C_n^k \equiv \prod C_{n_i}^{k_i} \mod p$
// $n = \sum n_ip^i$
// $k = \sum k_ip^i$
//  $FACTORIAL_n = n!$
int const FACTORIAL[];
int Lucas_Combine(int n, int k, int p) {
	return n>=k
		? FACTORIAL[n]*fast_mod_pow(FACTORIAL[k]*FACTORIAL[n-k], p-2, p) % p
		: 0;
}
int Lucas(int n, int k, int p) {
	return k!=0 ? (Lucas_Combine(n%p, k%p, p) * Lucas(n/p, k/p, p)) % p : 1;
}
