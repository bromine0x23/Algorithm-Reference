// $O(WN\sum{\log M_i})$
int N, W; // amount of items, knapsack capacity
int w[MAX_N], v[MAX_N], m[MAX_N]; // weight, value, multiplicity of items
int dp[MAX_W + 1];
void multiple_knapsack() {
	memset(dp, 0, sizeof(dp));
	for (int i = 0; i < N; ++i) {
		multiple_knapsack_one(dp, w[i], v[i], m[i]);
	}
}
void multiple_knapsack_one(int dp[], int w, int v, int m) {
	if (w * m >= v) {
		complete_knapsack_one(dp, w, v);
	}
	for (int k = 1; k < M; k *= 2) {
		zero_one_knapsack_one(dp, k * w, k * v);
	}
	zero_one_knapsack_one(dp, w * m, v * m);
}
