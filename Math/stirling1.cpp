// $O(n^2)$, calculate $|s(i, j)|$ where $1 \leqslant j \leqslant i\leqslant n$
int s[MAX_N][MAX_K];
void stirling1(int n) {
	memset(s, 0, sizeof(s)); // not necessary
	for (int i = 1; i <= n; ++i) {
		s[i][1] = (i - 1) * s[i - 1][1];
		for (int j = 2; j < i; ++j) {
			s[i][j] = s[i - 1][j - 1] + (i - 1) * s[i - 1][j];
		}
		s[i][i] = 1;
	}
	// samples for debug
	assert(s[4][2] == 11);
	assert(s[5][3] == 35);
	assert(s[8][1] == 5040);
}
