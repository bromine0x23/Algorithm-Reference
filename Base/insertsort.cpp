// $O(n^2)$
void insertsort(int datas[], int size) {
	for (int i = 1; i < size; ++i) {
		int current = datas[i];
		int j = i - 1;
		for (; j >= 0 && current < datas[j]; --j) {
			datas[j + 1] = datas[j];
		}
		datas[j + 1] = current;
	}
}
