int const FACTORIAL[]; // $FACTORIAL_n=n!$, i.e. $\{1, 1, 2, 6, 24, 120, 720, \ldots\}$
// $encantor(S)=\prod \rho_i*(n-i-1)!$, $\rho_i=\|\;\{S_k\mid S_k<S_i, i<k\leqslant n\}\;\|$
int encantor(int S[], int n) { // $S$ is a permutation of $\{1, 2, \ldots n\}$
	int result = 0;
	for (int i = 0; i< n - 1; ++i) {
		int rho = 0;
		for (int j = i + 1; j < n; ++j) {
			if (S[i] > S[j]) {
				++rho;
			}
		}
		result += FACTORIAL[n - i - 1] * rho;
	}
	return result;
}
// $S = decantor(x, n)$
void decantor(int S[], int x, int n) {
	std::vector<bool> is_appeared(n, false);
	for (int i = 0; i < n; ++i) {
		int t = x / FACTORIAL[n - i - 1] + 1;
		x %= FACTORIAL[n - i - 1];
		int j = 0;
		do {
			++j;
			if (!is_appeared[j]) {
				--t;
			}
		} while (t != 0);
		S[i] = j;
		is_appeared[j] = true;
	}
}
