// $O(m\alpha(n))$, $m$ is number of operations, $n$ is size of set
struct DisjointSet {
	std::vector<int> p; // parents
	std::vector<int> r; // rank
	DisjointSet(int s) : parent(s), rank(s, 0) {
		for (int si = 0; si < s; ++si) {
			p[i] = i;
		}
	}
	int find(int x) {
		// Optimize: compress path
		return x != p[x] ? p[x] = find(p[x]) : x;
	}
	void link(int x, int y) {
		// Optimize: link by rank
		x = find(x);
		y = find(y);
		if (r[x] < r[y]) {
			p[x] = y;
		} else {
			p[y] = x;
			if (r[x] == r[y]) {
				++r[x];
			}
		}
	}
};
