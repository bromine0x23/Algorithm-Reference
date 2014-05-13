// $O(n)$
int catalan[MAX_N];
void calculate_catalan(int n) {
	catalan[0] = 1;
	for (int i = 1; i <= n; ++i) {
		catalan[i] =  (4 * i - 2) * C[i - 1] / (i + 1);
	}
}
