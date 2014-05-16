// all $O(\log{n})$
int binary_search(int V[], int size, int goal) {
	int l = 0, r = size - 1;
	for (; l <= r;) {
		int m = l + (r - l) / 2; // $m = \lfloor \frac{l+r}{2} \rfloor$
		if (V[m] < goal) {
			l = m + 1; // $[l, r] \rightarrow [m+1, r]$
		} else if (V[m] > goal) {
			r = m - 1; // $[l, r] \rightarrow [l, m-1]$
		} else {
			return m; // $V_{m} = goal$
		}
	}
	return -1;
}
// i.e. \verb"std::lower_bound(v, v + size, pivot) - v"
int search_lower_bound(int V[], int size, int pivot) {
	int l = 0, r = size - 1;
	for (; l <= r;) {
		int m = l + (r - l) / 2; // $m = \lfloor \frac{l+r}{2} \rfloor$
		if (V[m] < p) {
			l = m + 1; // $[l, r] \rightarrow [m+1, r]$
		} else {
			r = m - 1; // $[l, r] \rightarrow [l, m-1]$
		}
	}
	return l; // $\forall i<l\;.\;V_{i}<pivot$
}
// i.e. \verb"std::upper_bound(v, v + size, pivot) - v"
int search_upper_bound(int V[], int size, int pivot) {
	int l = 0, r = size - 1;
	for (; l <= r;) {
		int m = l + (r - l) / 2; // $m = \lfloor \frac{l+r}{2} \rfloor$
		if (V[m] > p) {
			r = m - 1; // $[l, r] \rightarrow [l, m-1]$
		} else {
			l = m + 1; // $[l, r] \rightarrow [l, m-1]$
		}
	}
	return l; // $\forall i>l\;.\;V_{i}>pivot$
}
