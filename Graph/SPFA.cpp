// $O\left(kE\right)$, $k<2$ in normal
std::vector<int> SPFA(ListGraph const & graph, int source) {
	std::vector<int> dist(graph.V, INF);
	std::queue<int> Q;
	std::vector<bool> visited(graph.V, false);
	for (dist[source] = 0, Q.push(source), visited[source] = true; !Q.empty(); ) {
		int u = Q.front();
		Q.pop();
		visited[u] = false;
		for (int e = graph.head[u]; e != -1; e = graph.next[e]) {
			int v = graph.edges[e].v;
			int w = graph.edges[e].w;
			if (relax(dist, u, v, w) && !visited[v]) {
				Q.push(v);
				visited[v] = true;
			}
		}
	}
	return dist;
}
bool relax(std::vector<int> & dist, int u, int v, int w) {
	if(dist[u] + w < dist[v]) {
		dist[v] = dist[u] + w;
		return true;
	}
	return false;
}
