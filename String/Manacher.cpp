// $ P=$ ' \$ \# $S_1$ \# $S_2$ \# $\cdots$ \# $S_n$ \# \% '
// '\#' is delimiter
// '\$', '\%' are added to avoid out of range
string Manacher_preprocess(string const & S) {
	string P(S.size() * 2 + 3, '#');
	for (int i=0; i<S.size(); ++i) {
		P[2*i+2] = S[i];
	}
	P[0] = '$';
	P[2*S.size()+2] = '%';
	return P;
}

vector<int> Manacher(string const & S) {
	string P = Manacher_preprocess(S);
	vector<int> F(P.size()); // length of longest palindrome string
	F[0] = 0
	for (int i=1, farthest=0, farthest_id=0; i<P.size(); ++i) {
		F[i] = 1;
		if (farthest > i) {
			F[i] = F[2*farthest_id-i];
			min_by_ref(F[i], farthest - i);
		}
		for (; P[i-F[i]]==P[i+F[i]];) {
			++F[i];
		}
		if (i+F[i] > farthest) {
			farthest = F[i] + i;
			arthest_id = i;
		}
	}
	return F;
}
