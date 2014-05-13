// $O(WN)$
int N, W; // amount of items, knapsack capacity
int w[MAX_N], v[MAX_N]; // weight, value of items
int dp[MAX_W+1];
void complete_knapsack() {
	memset(dp, 0, sizeof(dp));
	for (int i = 0; i < N; ++i) {
		complete_knapsack_one(dp, w[i], v[i]);
	}
}
void complete_knapsack_one(int dp[], int w, int v) {
	for (int j = w; j <= W; ++j) {
		update_maximum(dp[j], dp[j - w] + v);
	}
}
