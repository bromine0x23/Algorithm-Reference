int DisjointSet::find(int x) {
	// Optimization : compress path
	return x!=parent[x] ? parent[x]=find(parent[x]) : x;
}
