vector< vector<int> > S;
void Stirling_second_kind(int n, int k) {
	S = vector<int>(n+1, vector<int>(k+1, 0));
	for (int i=0; i<=n; ++i) {
		S[i][i] = S[i][1] = 1;
	}
	for (int j=2; j<=k; ++j) {
		for (int i=j; i<n; ++i) {
			S[i+1][j] = S[i][j-1] + j * S[i][j];
		}
	}
}
