// $O(n)$
bool is_prime[MAX_N];
int prime[MAX_N];
int prime_count;
void prime_sieve(int n) {
	for (int i = 0; i < n; ++i) {
		is_prime[i] = true;
	}
	is_prime[1] = is_prime[0] = false;
	for (int i = 2; i < n; ++i) {
		if (is_prime[i]) {
			prime[prime_count++] = i;
		}

		for (int j = 0; j < prime_count && i * prime[j] < n; ++j) {
			is_prime[i * prime[j]] = false;
			if (i % prime[j] == 0) {
				break;
			}
		}
	}
}
