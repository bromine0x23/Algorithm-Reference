// adjacency matrix : $O(V^2)$
// binary heap + adjacency list : $O(E \log V)$
// Fibonacci heap + adjacency list: $O(E + V \log V)$
int weight[MAX_VERTEX];
SPListGraph const & graph; // \SourceRef{source:graph}
bool prim_compare(int lhs, int rhs) {
	return weight[lhs] < weight[rhs] || (weight[lhs] == weight[rhs] && lhs < rhs);
}
int prim(ListGraph const & graph) {
	int weight_sum = 0;
	fill_range(weight, weight + graph.vertex_num, INF); // \SourceRef{source:utility}
	weight[0] = 0;
	std::set<int, bool(*)(int ,int)> queue(prim_compare); // use binary heap
	for (int vi = 0; vi < graph.vertex_num; ++vi) {
		queue.insert(vi);
	}
	for (; !queue.empty(); ) {
		int u = *queue.begin();
		queue.erase(u);
		weight_sum += weight[u];
		for (SPEdge * edge = graph.head[u]; edge != NULL; edge = edge->next) {
			if (queue.count(edge->v) > 0 && edge->w < weight[edge->v]) {
				queue.erase(edge->v);
				weight[edge->v] = edge->w;
				queue.insert(edge->v);
			}
		}
	}
	return weight_sum;
}
