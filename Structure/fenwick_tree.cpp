struct FenwickTree {
	// index start from 1.
	int size;
	std::vector<int> bit;
	BinaryIndexedTree(int size) : size(size), bit(size + 1, 0) {}
	BinaryIndexedTree(std::vector<int> V) : size(values.size() - 1), bit(size + 1, 0) {
		for (int i = 1; i <= size; ++i) {
			increase(i, V[i]);
		}
	}
	// last one of $x$
	static int low_bit(int x) {
		return x & (~x + 1); // for signed: $x \& -x$
	}
	// $O(\log n)$, $V_i = V_i + \delta$
	void increase(int i, int delta) {
		for (int j = i; j <= size; j += low_bit(j)) {
			bit[j] += delta;
		}
	}
	// $O(\log n)$, $\operatorname{sum}(k)=\sum_{i=1}^{k}V_i$, i.e. $V_k=\operatorname{sum}(k)-\operatorname{sum}(k-1)$
	int sum(int k) {
		int ans = 0;
		for (int i = k; i > 0; i -= low_bit(i)) {
			ans += bit[i];
		}
		return ans;
	}
};
