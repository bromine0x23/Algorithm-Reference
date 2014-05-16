// $O(n)$, calculate $C_i$ where $0 \leqslant i\leqslant n$
int C[MAX_N];
void catalan(int n) {
	C[0] = 1;
	for (int i = 1; i <= n; ++i) {
		C[i] =  (4 * i - 2) * C[i - 1] / (i + 1);
	}
	// samples for debug
	assert(C[4] == 14);
	assert(C[5] == 42);
	assert(C[8] == 1430);
}
