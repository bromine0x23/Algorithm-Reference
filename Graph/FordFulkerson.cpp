// $O(E|f|)$, $f$ is max flow value
Graph graph;
vector< vector<int> > flow;
vector<int> prev;
int FordFulkerson(int source, int sink) {
	int max_flow = 0;
	flow = vector< vector<int> >(
		graph.V,
		vector<int>(graph.V, 0)
	);
	prev = vector<int>(graph.V);
	prev[source] = -1;

	while (true) {
		FordFulkerson_DFS(source, sink);
		if (!visited[sink]) {
			break;
		}
		max_flow += update(graph, flow, prev, sink);
	}

	return max_flow;
}
void FordFulkerson_DFS(int u, int sink) {
	for (int v=0; v<graph.V; ++v) {
		if (prev[v] == -1 && graph.capacity(u, v) > flow[u][v]) {
			prev[v] = u;
			FordFulkerson_DFS(v, sink);
		}
	}
}
