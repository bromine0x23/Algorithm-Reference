// helper struct, used in set
struct DijkstraCmp {
	vector<int> & dist;
	DijkstraCmp(vector<int> & d) : dist(d) { }
	bool operator()(int const & lhs, int const & rhs) const {
		return dist[lhs] < dist[rhs] || (dist[lhs]==dist[rhs] && lhs < rhs);
	}
};
// $O\left(E\lg V\right)$
vector<int> Dijkstra(Graph const & graph, int source) {
	vector<int> dist(graph.vertex_num, INF);
	dist[source] = 0;

	set<int, DijkstraCmp> Q(DijkstraCmp(dist));
	for(int vi=0; vi<graph.vertex_num; ++vi) {
		Q.insert(vi);
	}

	vector<bool> in_q(vertex_num, true);

	while (!Q.empty()) {
		int u = *Q.begin(); Q.erase(u); in_q[u] = false;
		for (int v=0; v<graph.vertex_num; ++v) {
			if (graph.weight(u, v) != INF && in_q[v]) {
				if (dist[u] + graph.weight(u, v) < dist[v]) {
					Q.erase(v);
					dist[v] = dist[u] + graph.weight(u, v);
					Q.insert(v);
				}
			}
		}
	}
	return dist;
}
