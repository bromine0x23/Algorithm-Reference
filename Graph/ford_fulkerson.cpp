// $O(E|f|)$, $f$ is max flow value
Graph graph;
std::vector< std::vector<int> > flow;
std::vector<int> prev;
void ford_fulkerson_dfs(int u, int sink) {
	for (int v = 0; v < graph.V; ++v) {
		if (prev[v] == -1 && graph.capacity(u, v) > flow[u][v]) {
			prev[v] = u;
			ford_fulkerson_dfs(v, sink);
		}
	}
}
int ford_fulkerson(int source, int sink) {
	int max_flow = 0;
	flow = std::vector< std::vector<int> >(graph.V, std::vector<int>(graph.V, 0));
	prev = std::vector<int>(graph.V);
	prev[source] = -1;
	for (; true; ) {
		ford_fulkerson_dfs(source, sink);
		if (!visited[sink]) {
			break;
		}
		max_flow += flow_update(sink);
	}
	return max_flow;
}
