// $O(n\log{n})$
void quicksort(int datas[], int const size) {
	for (int i, j; size > 0; size = i) {
		int pivot = datas[0];
		for (i = 0, j = size-1; i < j; ) {
			for (; i < j && pivot < datas[j]; --j) { }
			if (i < j) {
				datas[i++] = datas[j];
			}
			for (; i < j && datas[i] < pivot; ++i) { }
			if (i < j) {
				datas[j--] = datas[i];
			}
		}
		datas[i] = pivot;
		quicksort(datas+i+1, size-i-1);
	}
}
