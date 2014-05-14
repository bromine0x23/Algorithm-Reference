// adjacency matrix : $O(V^2)$
// binary heap + adjacency list : $O(E \log V)$
// Fibonacci heap + adjacency list: $O(E + V \log V)$
struct DijkstraComparer {
	std::vector<int> & dist;
	DijkstraComparer(std::vector<int> & dist) : dist(dist) { }
	bool operator()(int const & lhs, int const & rhs) const {
		return dist[lhs] < dist[rhs] || (dist[lhs] == dist[rhs] && lhs < rhs);
	}
};
std::vector<int> dijkstra(ListGraph const & graph, int source) {
	std::vector<int> dist(graph.vertex_num, INF);
	dist[source] = 0;
	std::set<int, DijkstraComparer> queue(DijkstraComparer(dist));
	for (int vi = 0; vi < graph.vertex_num; ++vi) {
		queue.insert(vi);
	}
	std::vector<bool> in_queue(graph.vertex_num, true);
	for (; !queue.empty(); ) {
		int u = *queue.begin();
		queue.erase(u);
		in_queue[u] = false;
		for (int e = graph.head[u]; e != -1; e = graph.next[e] ) {
			int v = graph.edges[e].v;
			int w = graph.edges[e].w;
			if (in_queueq[v] && dist[u] + w < dist[v]) {
				queue.erase(v);
				dist[v] = dist[u] + w;
				queue.insert(v);
			}
		}
	}
	return dist;
}
