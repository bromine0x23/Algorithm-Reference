// $O(n \log n)$
// merge $L = [V_{0}, \cdots V_{l-1}]$ and $R = [V_{l}, \cdots V_{r-1}]$
void merge(int V[], int l, int r) {
	int length_l = l;
	int length_r = r - l;
	int * L = new int[length_l];
	for (int li = 0; li < length_l; ++li) {
		L[li] = V[li];
	}
	int * R = new int[length_r];
	for (int ri = 0; ri < length_r; ++ri) {
		R[ri] = V[p + ri];
	}
	int li = 0;
	int ri = 0;
	int vi = 0;
	for (; li < length_l && ri < length_r; ) {
		if (R[ri] < L[li]) {
			V[vi++] = R[ri++];
			// for count inversion: \verb"count += length_l - li;"
		} else {
			V[vi++] = L[li++];
		}
	}
	for (; li < length_l; V[vi++] = L[li++]) {}
	for (; ri < length_r; V[vi++] = R[ri++]) {}
	delete [] L;
	delete [] R;
}
void mergesort(int V[], int size) {
	if (size > 1) {
		int m = size / 2;
		mergesort(V, m);
		mergesort(V + m, size - m);
		merge(V, m, size);
	}
}
