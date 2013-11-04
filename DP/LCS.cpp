enum Pace { LEFT, UP, LEFT_UP };
vector< vector<int> > dp;
vector< vector<Pace> > path;
void LCIS(string const & X, string const & Y) {
	int x_len = X.length(), y_len = Y.length();
	dp = vector< vector<int> >(x_len+1, vector<int>(y_len+1, 0));
	path = vector< vector<Pace> >(x_len+1, vector<Pace>(y_len+1, 0));
	for (int xi=0; xi < x_len; ++xi) {
		for (int yi=0; yi < y_len; ++yi) {
			if (X[xi] == Y[yi]) {
				dp[xi+1][yi+1] = dp[xi][yi] + 1;
				path[xi+1][yi+1] = LEFT_UP;
			} else if (f[xi][yi+1] > dp[xi+1][yi]) {
				dp[xi+1][yi+1] = dp[xi][yi+1];
				path[xi+1][yi+1] = UP;
			} else {
				dp[xi+1][yi+1] = dp[xi+1][yi];
				path[xi+1][yi+1] = LEFT;
			}
		}
	}
}
void print_path(string const & X, int i, int j) {
	if (i>0 && j>0) {
		if (path[i-1][j-1] == LEFT_UP) {
			print_path(X, i-1, j-1);
			putchar(X[i-1]);
		} else if (path[i-1][j-1] == UP) {
			print_path(X, i-1, j);
		} else {
			print_path(X, i, j-1);
		}
	}
}

