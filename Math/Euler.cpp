// calculate Euler function value mix with prime sieve
int phi[MAXN];
bool not_prime[MAXN];
int prime[MAXN], prime_count;
void Euler_function() {
	for (int i=0; i<MAXN; ++i) {
		not_prime[i] = false;
	}
	phi[1] = 1;
	not_prime[1] = not_prime[0] = true;
	for (int i=2; i<MAXN; ++i) {
		if (!not_prime[i]) {
			phi[i] = i-1;
			prime[prime_count++] = i;
		}
		for (int j=0; j<prime_count && i*prime[j]<MAXN; ++j) {
			not_prime[i*prime[j]] = true;
			if (i % prime[j] == 0) {
				phi[i*prime[j]] = phi[i]*prime[j];
				break;
			} else {
				phi[i*prime[j]] = phi[i]*(prime[j]-1);
			}
		}
	}
}
