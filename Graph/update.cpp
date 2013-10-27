int update(Graph const & graph, vector<int> & flow, vector<int> const & prev, int sink) {
	int increment = INF;
	for (int v = sink; prev[v] != -1; v = prev[v]) {
		min_ref(increment, graph.edge(prev[v], v).w - flow[prev[v]][v]);
	}
	for (int v = sink; prev[v] != -1; v = prev[v]) {
		flow[prev[v]][v] += increment;
		flow[v][prev[v]] -= increment;
	}
	return increment;
}
