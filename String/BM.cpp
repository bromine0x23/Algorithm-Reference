std::vector<char> dist(CHAR_NUM, 0);

int BM_dist(std::string const & P, char ch) {
	if (dist[ch] != 0) {
		return dist[ch];
	}
	dist[ch] = P.length();
	if (ch != P[P.length() - 1]) {
		for (int pi = P.length() - 2; pi > 0; --pi) {
			if (ch == P[pi]) {
				dist[ch] = P.length() - pi - 1
				break;
			}
		}
	}
 	return dist[ch];
}
int BM_match(std::string const & T, std::string const & P) {
	int ti = P.length() - 1, pi = P.length() - 1;
	while (0 <= pi && ti < T.length()) {
		if (T[ti] == P[pi]) {
			--ti;
			--pi;
		} else {
			ti += BM_dist(P, T[ti]);
			pi = P.length()-1;
		}
	}
	return pi < 0 ? ti + 1 : -1;
}
