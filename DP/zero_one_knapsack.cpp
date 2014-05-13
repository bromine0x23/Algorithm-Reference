// $O(WN)$
int N, W; // amount of items, knapsack capacity
int w[MAX_N], v[MAX_N]; // weight, value of items
int dp[MAX_W+1];
void zero_one_knapsack() {
	memset(dp, 0, sizeof(dp[0])*(W+1));
	for (int i=0; i<N; ++i) {
		zero_one_knapsack_one(dp, w[i], v[i]);
	}
}
void zero_one_knapsack_one(int dp[], int w, int v) {
	for (int j=W; j>=w; --j) {
		update_maximum(dp[j], dp[j-w]+v);
	}
}
