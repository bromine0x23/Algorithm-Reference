// $O(nk)$, calculate $S_{i j}$ where $i\leqslant n\wedge j\leqslant k$
int S[MAX_N][MAX_K];
void Stirling_second_kind(int n, int k) {
	for (int i = 0; i <= n; ++i) {
		for (int j = 0; j <= k; ++j) {
			S[i][j] = 0;
		}
	}
	for (int i = 0; i <= n; ++i) {
		S[i][i] = S[i][1] = 1;
	}
	for (int j = 2; j <= k; ++j) {
		for (int i = j; i < n; ++i) {
			S[i+1][j] = S[i][j-1] + j * S[i][j];
		}
	}
}
