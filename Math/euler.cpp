// $O(n)$, calculate Euler function value mix with prime sieve
int phi[MAX_N];
bool is_prime[MAX_N];
int prime[MAX_N];
int prime_count;
void euler(int n) {
	for (int i = 0; i < n; ++i) {
		is_prime[i] = true;
	}
	is_prime[1] = is_prime[0] = false;
	phi[1] = 1;
	for (int i = 2; i < n; ++i) {
		if (is_prime[i]) {
			phi[i] = i-1;
			prime[prime_count++] = i;
		}
		for (int j=0; j < prime_count && i * prime[j] < n; ++j) {
			is_prime[i*prime[j]] = false;
			if (i % prime[j] == 0) {
				phi[i * prime[j]] = phi[i] * prime[j];
				break;
			} else {
				phi[i * prime[j]] = phi[i] * (prime[j] - 1);
			}
		}
	}
	// samples for debug
	assert(phi[4] == 2);
	assert(phi[29] == 28);
	assert(phi[32] == 16);
}
