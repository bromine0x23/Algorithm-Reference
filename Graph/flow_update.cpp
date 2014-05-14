extern Graph graph;
extern std::vector< std::vector<int> > flow;
extern std::vector<int> prev;
int flow_update(int sink) {
	int increment = INF;
	for (int v = sink; prev[v] != -1; v = prev[v]) {
		update_minimum(increment, graph.edge(prev[v], v).w - flow[prev[v]][v]);
	}
	for (int v = sink; prev[v] != -1; v = prev[v]) {
		flow[prev[v]][v] += increment;
		flow[v][prev[v]] -= increment;
	}
	return increment;
}
