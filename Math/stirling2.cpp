// $O(n^2)$, calculate $S(i, j)$ where $1 \leqslant j \leqslant i\leqslant n$
int S[MAX_N][MAX_K];
void stirling2(int n) {
	memset(S, 0, sizeof(S)); // not necessary
	for (int i = 1; i <= n; ++i) {
		S[i][1] = 1;
		for (int j = 2; j < i; ++j) {
			S[i][j] = S[i - 1][j - 1] + j * S[i - 1][j];
		}
		S[i][i] = 1;
	}
	// samples for debug
	assert(S[4][2] == 7);
	assert(S[5][3] == 25);
	assert(S[8][1] == 1);
}
