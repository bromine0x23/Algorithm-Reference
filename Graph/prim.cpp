// adjacency matrix : $O(V^2)$
// binary heap + adjacency list : $O(E \log V)$
// Fibonacci heap + adjacency list: $O(E + V \log V)$
struct PrimComparer {
	std::vector<int> & weight;
	PrimComparer(std::vector<int> & weight) : weight(weight) { }
	bool operator()(int const & lhs, int const & rhs) const {
		return weight[lhs] < weight[rhs] || (weight[lhs] == weight[rhs] && lhs < rhs);
	}
};
int prim(ListGraph const & graph) {
	std::vector<int> weight(graph.vertex_num, INF);
	weight[0] = 0;
	std::set<int, PrimComparer> queue(PrimComparer(weight));
	for (int vi = 0; vi < graph.vertex_num; ++vi) {
		queue.insert(vi);
	}
	std::vector<bool> in_queue(graph.vertex_num, true);
	int weight_sum = 0;
	for (; !queue.empty(); ) {
		int u = *queue.begin();
		queue.erase(u);
		in_queue[u] = false;
		weight_sum += weight[u];
		for (int e = graph.head[u]; e != -1; e = graph.next[e] ) {
			int v = graph.edges[e].v;
			int w = graph.edges[e].w;
			if (in_queue[v] && w < weight[v]) {
				queue.erase(v);
				weight[v] = w;
				queue.insert(v);
			}
		}
	}
	return weight_sum;
}
