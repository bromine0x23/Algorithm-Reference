// $O(VE^2)$
int EdmondsKarp(Graph & graph, int source, int sink) {
	int max_flow = 0;
	vector< vector<int> > flow(graph.V, vector<int>(graph.V, 0));
	for (vector<int> prev; EdmondsKarp_BFS(graph, flow, prev, source, sink); ) {
		max_flow += update(graph, flow, prev, sink);
	}
	return max_flow;
}
bool EdmondsKarp_BFS(Graph & graph, vector< vector<int> > & flow, vector<int> & prev, int source, int sink) {
	prev = vector<int>(graph.V, -1);
	queue<int> Q;
	for (Q.push(source); !Q.empty(); ) {
		int u = Q.front(); Q.pop();
		for (int e = graph.head[u]; e != -1; e = graph.next[e]) {
			int v = graph.edges[e].v, w = graph.edges[e].w;
			if (prev[v] == -1 && w > flow[u][v]) {
				prev[v] = u; Q.push(v);
			}
		}
	}
	return prev[sink] != -1;
}
