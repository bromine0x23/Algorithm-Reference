// all $O(\log{n})$
int binary_search(int const V[], int const size, int const g /* goal */) {
	int l = 0, r = size - 1;
	for (; l <= r;) {
		int m = l + (r - l) / 2;
		if (V[m] < g) {
			l = m + 1;
		} else if (V[m] > g) {
			r = m - 1;
		} else {
			return m; // $V_{m}<g$
		}
	}
	return -1;
}

int search_lower_bound(int const V[], int const size, int const p /* pivot */) {
	int l = 0, r = size - 1;
	for (; l <= r;) {
		int m = l + (r - l) / 2;
		if (V[m] < p) {
			l = m + 1;
		} else {
			r = m - 1;
		}
	}
	return l; // $\forall i<l\;.\;V_{i}<p$
}

int search_upper_bound(int const V[], int const size, int const p /* pivot */) {
	int l = 0, r = size - 1;
	for (; l <= r;) {
		int m = l + (r - l) / 2;
		if (V[m] > p) {
			r = m - 1;
		} else {
			l = m + 1;
		}
	}
	return l; // $\forall i>l\;.\;V_{i}>p$
}
