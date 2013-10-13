void DisjointSet::link(int x, int y) {
	// Optimization : union by rank
	x = find(x); y = find(y);
	if (rank[x] < rank[y]) {
		parent[x] = y;
	} else {
		parent[y] = x;
		rank[x] += (rank[x] == rank[y]);
	}
}
