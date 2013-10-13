Graph graph;
vector< vector<int> > flow;
vector<int> prev;

int FordFulkerson(int source, int sink) {
	// $O(E|f|)$, $f$ is max flow value
	int max_flow = 0;
	flow = vector< vector<int> >(
		graph.vertex_num,
		vector<int>(graph.vertex_num, 0)
	);
	prev = vector<int>(graph.vertex_num);
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
	for (int v=0; v<graph.vertex_num; ++v) {
		if (prev[v] == -1 && graph.capacity(u, v) > flow[u][v]) {
			prev[v] = u;
			FordFulkerson_DFS(v, sink);
		}
	}
}
