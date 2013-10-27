int n, m;
int val[MAXN][MAXN];

int idx[MAXN];
int pow2[LOG2_MAXN];
int max_val[MAXM][MAXN][MAXN];

void RQM2D_init() {
	idx[0] = -1;
	for (int i=1; i<N; ++i) {
		idx[i] = idx[i-1] + (pow_of_2(i) ? 1 : 0); // pow\_of\_2(i) := !(i\&(i-1))
	}
	for (int i=0; i<LOG2_MAXN; ++i) {
		pow2[i] = 1 << i;
	}
}
void RMQ2D() {
	int mind = min_by_val(n,m);
	for (int k=0; pow2[k]<=mind; ++k) {
		for (int i=1; i<=n; ++i) {
			for (int j=1; j<=m; ++j) {
				max_val[k][i][j] = val[i][j];
			}
		}
	}
	for (int k=1; pow2[k]<=mind; ++k) {
		for (int i=1; i<=n; ++i) {
			for (int j=1; j<=m; ++j) {
				max_val[k][i][j] = max_val[k-1][i][j];
				if (i + pow2[k-1] <= n) {
					max_by_ref(max_val[k][i][j], max_val[k-1][i+pow2[k-1]][j]);
				}
				if (j + pow2[k-1] <= m) {
					max_by_ref(max_val[k][i][j], max_val[k-1][i][j+pow2[k-1]]);
				}
				if (i + pow2[k-1] <= n && j + pow2[k-1] <= m) {
					max_by_ref(max_val[k][i][j], max_val[k-1][i+pow2[k-1]][j+pow2[k-1]]);
				}
			}
		}
	}
}
int RMQ2D_query(int x1, int y1, int x2, int y2) {
	int k = min_by_val(idx[x2-x1+1], idx[y2-y1+1]);
	int max_ans = max_val[0][x1][y1];
	for (int i=x1; i<=x2; i+=pow2[k]) {
		if (i+pow2[k]>x2) {
			i = x2 - pow2[k] + 1;
		}
		for (int j=y1; j<=y2; j+=pow2[k]) {
			if(j+pow2[k]>y2) {
				j = y2 - pow2[k] + 1;
			}
			max_by_ref(max_ans, max_val[k][i][j]);
		}
	}
	return max_ans;
}
