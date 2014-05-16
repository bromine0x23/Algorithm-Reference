// $O(n^2)$, calculate $B_i$ where $0 \leqslant i\leqslant n$
int B[MAX_N][MAX_K]; // $B_{i0}$ is $B_{i}$
void bell(int n) {
	memset(B, 0, sizeof(B)); // not necessary
	B[0][0] = 1;
	for (int i = 1; i <= n; ++i) {
		B[i][0] = B[i-1][i-1];
		for (int j = 1; j <= i; ++j) {
			B[i][j] = B[i - 1][j - 1] + B[i][j - 1];
		}
	}
	// samples for debug
	assert(B[4][0] == 15);
	assert(B[5][0] == 52);
	assert(B[8][0] == 4140);
}
