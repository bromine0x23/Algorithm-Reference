int LCS(string const & X, string const & Y) {
	int x_len = X.length(), y_len = Y.length();
	vector< vector<int> > f(x_len+1, vector<int>(y_len+1, 0));

	for (int xi=0; xi < x_len; ++xi) {
		for (int yi=0; yi < y_len; ++yi) {
			if (X[xi] == Y[yi]) {
				f[xi+1][yi+1] = f[xi][yi] + 1;
			} else {
				f[xi+1][yi+1] = max_val(f[xi][yi+1], f[xi-1][yi]);
			}
		}
	}

	return f[x_len][y_len];
}
