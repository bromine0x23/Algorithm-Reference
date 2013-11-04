// $O(n)$
bool not_prime[MAXN];
int prime[MAXN], prime_count;
void prime_sieve() {
	for (int i=0; i<MAXN; ++i) {
		not_prime[i] = false;
	}
	not_prime[1] = not_prime[0] = true;
	for (int i=2; i<MAXN; ++i) {
		if (!not_prime[i]) {
			prime[prime_count++] = i;
		}
		for (int j=0; j<prime_count && i*prime[j]<MAXN; ++j) {
			not_prime[i*prime[j]] = true;
			if (i % prime[j] == 0) {
				break;
			}
		}
	}
}
