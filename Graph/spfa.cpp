// $O(kE)$, $k<2$ in normal
std::vector<int> spfa(ListGraph const & graph, int source) {
	std::vector<int> dist(graph.vertex_num, INF);
	std::queue<int> queue;
	std::vector<bool> visited(graph.vertex_num, false);
	dist[source] = 0;
	queue.push(source);
	visited[source] = true;
	for (; !queue.empty(); ) {
		int u = queue.front();
		queue.pop();
		visited[u] = false;
		for (int e = graph.head[u]; e != -1; e = graph.next[e]) {
			int v = graph.edges[e].v;
			int w = graph.edges[e].w;
			if (relax(dist, u, v, w) && !visited[v]) {
				queue.push(v);
				visited[v] = true;
			}
		}
	}
	return dist;
}
bool spfa_relax(std::vector<int> & dist, int u, int v, int w) {
	if(dist[u] + w < dist[v]) {
		dist[v] = dist[u] + w;
		return true;
	}
	return false;
}
