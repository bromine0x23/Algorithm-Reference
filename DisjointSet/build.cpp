DisjointSet::DisjointSet(int size) : parent(size), rank(size) {
	for (int si=0; si<size; ++si) {
		parent[i] = i;
		rank[i] = 0;
	}
}
