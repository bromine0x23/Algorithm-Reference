// $ P=$ ' \$ \# $S_1$ \# $S_2$ \# $\cdots$ \# $S_n$ \# \% '
// '\#' is delimiter
// '\$', '\%' are added to avoid out of range
std::string Manacher_preprocess(std::string const & S) {
	std::string P(2 * (S.size() + 1) + 1, '#');
	for (int i = 0; i < S.size(); ++i) {
		P[2 * (i + 1)] = S[i];
	}
	P[0] = '$';
	P[2 * (S.size() + 1)] = '%';
	return P;
}

std::vector<int> Manacher(std::string const & S) {
	std::string P = Manacher_preprocess(S);
	std::vector<int> F(P.size()); // length of longest palindrome string
	F[0] = 0
	for (int i = 1, farthest = 0, farthest_id = 0; i < P.size(); ++i) {
		F[i] = 1;
		if (farthest > i) {
			F[i] = F[2 * farthest_id-i];
			update_minimum(F[i], farthest - i);
		}
		for (; P[i - F[i]]==P[i + F[i]];) {
			++F[i];
		}
		if (i + F[i] > farthest) {
			farthest = F[i] + i;
			arthest_id = i;
		}
	}
	return F;
}
