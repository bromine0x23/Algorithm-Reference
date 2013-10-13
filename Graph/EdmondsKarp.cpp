Graph graph;
vector< vector<int> > flow;
vector<int> prev;

int EdmondsKarp(int source, int sink) {
	// $O(VE^2)$
	int max_flow = 0;
	flow = vector< vector<int> >(
		graph.vertex_num,
		vector<int>(graph.vertex_num, 0)
	);
	while (EdmondsKarp_BFS(source, sink)) {
		max_flow += update(graph, flow, prev, sink);
	}
	return max_flow;
}

bool EdmondsKarp_BFS(int source, int sink) {
	prev = vector<int>(graph.vertex_num, -1);
	queue<int> Q;
	Q.push(source);
	while (!Q.empty()) {
		int u = Q.front(); Q.pop();
		for (int v=0; v<graph.vertex_num; ++v) {
			if (prev[v] == -1 && graph.capacity(u, v) > flow[u][v]) {
				prev[v] = u;
				Q.push(v);
			}
		}
	}
	return prev[sink] != -1;
}
