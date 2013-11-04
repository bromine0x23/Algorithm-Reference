// helper struct, used in set
struct DijkstraCmp {
	vector<int> & dist;
	DijkstraCmp(vector<int> & D) : dist(D) { }
	bool operator()(int const & lhs, int const & rhs) const {
		return dist[lhs] < dist[rhs] || (dist[lhs]==dist[rhs] && lhs < rhs);
	}
};
// $O\left(E\lg V\right)$
vector<int> Dijkstra(ListGraph const & graph, int source) {
	vector<int> dist(graph.V, INF); dist[source] = 0;
	set<int, DijkstraCmp> Q(DijkstraCmp(dist));
	for (int vi=0; vi<graph.V; ++vi) { Q.insert(vi); }
	vector<bool> in_q(graph.V, true);
	for (; !Q.empty(); ) {
		int u = *Q.begin(); Q.erase(u); in_q[u] = false;
		for (int e = graph.head[u]; e != -1; e = graph.next[e] ) {
			int v = graph.edges[e].v, w = graph.edges[e].w;
			if (in_q[v] && dist[u] + w < dist[v]) {
				Q.erase(v); dist[v] = dist[u] + w; Q.insert(v);
			}
		}
	}
	return dist;
}
