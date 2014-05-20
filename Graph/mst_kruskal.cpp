// $O(E \log E)$, or equivalently $O(E \log V)$
struct KruskalEdge {
	int u, v; // form, to
	int w; // weight
	bool operator<(KruskalEdge const & rhs) {
		return w < rhs.w || w == rhs.w && u < rhs.u;
	}
};
int kruskal(std::vector<KruskalEdge> const & edges, int vertex_num) {
	sort(edges.begin(), edges.end());
	DisjointSet set(vertex_num); // \SourceRef{source:disjoint_set}
	int weight_sum = 0;
	std::vector<KruskalEdge> edge = edges.begin();
	for (int vertex_count = 1; edge != edges.end() && vertex_count < vertex_num; ++edge) {
		if (set.find(edge->u) != set.find(edge->v)) {
			set.link(edge->u, edge->v);
			++vertex_count;
			weight_sum += edge->w;
		}
	}
	return weight_sum;
}
