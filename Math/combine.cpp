// $O(n^2)$, calculate $C_i^j$ where $0 \leqslant j \leqslant i\leqslant n$
int C[MAX_N][MAX_K];
void combine(int n) {
	memset(C, 0, sizeof(C)); // not necessary
	for (int i = 0; i <= n; ++i) {
		C[i][0] = 1;
		for (int j = 1; j < i; ++j) {
			C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
		}
		C[i][i] = 1;
	}
	// samples for debug
	assert(C[4][2] == 6);
	assert(C[5][3] == 10);
	assert(C[8][1] == 8);
}
