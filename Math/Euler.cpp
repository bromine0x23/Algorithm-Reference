// $O(n)$, calculate Euler function value mix with prime sieve
int phi[MAXN];
bool is_prime[MAXN];
int prime[MAXN], prime_count;
void Euler_function() {
	is_prime[1] = is_prime[0] = false;
	for (int i=0; i<MAXN; ++i) {
		is_prime[i] = true;
	}

	phi[1] = 1;
	for (int i=2; i<MAXN; ++i) {
		if (is_prime[i]) {
			phi[i] = i-1;
			prime[prime_count++] = i;
		}

		for (int j=0; j<prime_count && i*prime[j]<MAXN; ++j) {
			is_prime[i*prime[j]] = false;
			if (i % prime[j] == 0) {
				phi[i*prime[j]] = phi[i]*prime[j];
				break;
			} else {
				phi[i*prime[j]] = phi[i]*(prime[j]-1);
			}
		}
	}
}
