// $O(E\lg V)$
int Kruskal(std::vector<Edge> const & edges, int V, int E) {
	sort(edges.begin(), edges.end());
	DisjointSet set(V);
	int sum = 0;
	for (int ei = 0, vc = 1; ei < E && vc < V; ++ei) {
		if (set.find(edges[ei].u) != set.find(edges[ei].v)) {
			set.link(edges[ei].u, edges[ei].v);
			++vc;
			sum += edges[ei].w;
		}
	}
	return sum;
}
