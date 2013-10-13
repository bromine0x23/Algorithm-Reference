// $next_q=\max{\left\{k : k<q \wedge P_k \sqsupset P_q\right\}}$
// $\Theta\left(|P|\right)$, in preprocess
// $\Theta\left(|T|\right)$, in one match
vector<int> KMP_build_next(string const & P) {
	vector<int> next(P.length()+1, -1);
	int ni = -1, pi = 0;
	while (pi < P.length()) {
		if (ni == -1 || P[pi] == P[ni]) {
			++pi; ++ni;
			next[pi] = ni;
			// Optimization : when $P_{pi}=P_{ni}$,  let $next_{pi}=next_{ni}$
		} else {
			ni = next[ni];
		}
	}
	return next;
}

int KMP_match(string const & T, string const & P) {
	vector<int> next = KMP_build_next(P);
	int ti=0, pi=0;
	while (ti < T.length() && pi < P.length()) {
		if (pi < 0 || T[ti] == P[pi]) {
			++ti; ++pi;
		} else {
			pi = next[pi];
		}
	}
	return pi == P.length() ? ti - P.length() : -1;
}

vector<int> KMP_match_all(string const & T, string const & P) {
	vector<int> next = build_next(P), ans;
	int ti=0, pi=0;
	while (ti < T.length()) {
		if (pi < 0 || T[ti] == P[pi]) {
			++ti; ++pi;
			if (pi == P.length()) {
				ans.push_back(ti - P.length());
				pi = next[pi];
			}
		} else {
			pi = next[pi];
		}
	}
	return ans;
}
