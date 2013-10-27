int n;
int val[MAXN];

int pow2[LOG2_MAXN];
int idx[MAXN];
int max_val[MAXM][MAXN];

void RMQ1D_init() {
	idx[0] = -1;
	for (int i=1; i<N; ++i) {
		idx[i] = idx[i-1] + (pow_of_2(i) ? 1 : 0); // pow\_of\_2(i) := !(i\&(i-1))
	}
	for (int i=0; i<LOG2_MAXN; ++i) {
		pow2[i] = 1 << i;
	}
}
void RMQ1D() {
	for (int i=1; i<=n; ++i) {
		max_val[0][i] = val[i];
	}
	for (int i=1; pow2[i] <= n; ++i) {
		for (int j=1; j + pow2[i]-1 <= n; ++j) {
			max_val[i][j] = max_by_val(max_val[i-1][j+pow2[i-1]], max_val[i-1][j]);
		}
	}
}
int RMQ1D_query(int l, int r) {
	int t = idx[r-l+1];
	return  max_by_val(max_val[t][l], max_val[t][r-p[t]+1]);
}
