// $O(E \log E)$, or equivalently $O(E \log V)$
int kruskal(std::vector<Edge> const & edges, int vertex_num) {
	sort(edges.begin(), edges.end());
	DisjointSet set(vertex_num);
	int weight_sum = 0;
	for (int ei = 0, vc = 1; ei < edges.size() && vc < vertex_num; ++ei) {
		if (set.find(edges[ei].u) != set.find(edges[ei].v)) {
			set.link(edges[ei].u, edges[ei].v);
			++vc;
			weight_sum += edges[ei].w;
		}
	}
	return weight_sum;
}
