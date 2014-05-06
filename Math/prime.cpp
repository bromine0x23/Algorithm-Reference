// $O(n)$
bool is_prime[MAXN];
int prime[MAXN], prime_count;
void prime_sieve() {
	is_prime[1] = not_prime[0] = false;
	for (int i = 2; i < MAXN; ++i) {
		is_prime[i] = true;
	}

	for (int i = 2; i < MAXN; ++i) {
		if (is_prime[i]) {
			prime[prime_count++] = i;
		}

		for (int j = 0; j < prime_count && i * prime[j] < MAXN; ++j) {
			is_prime[i * prime[j]] = false;
			if (i % prime[j] == 0) {
				break;
			}
		}
	}
}
