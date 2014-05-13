// $O(VE^2)$
Graph graph;
std::vector< std::vector<int> > flow;
std::vector<int> prev;
int EdmondsKarp(int source, int sink) {
	int max_flow = 0;
	std::vector< std::vector<int> > flow(graph.V, std::vector<int>(graph.V, 0));
	for (std::vector<int> prev; EdmondsKarp_BFS(source, sink); ) {
		max_flow += flow_update(sink);
	}
	return max_flow;
}
bool EdmondsKarp_BFS(int source, int sink) {
	prev = std::vector<int>(graph.V, -1);
	std::queue<int> Q;
	for (Q.push(source); !Q.empty(); ) {
		int u = Q.front();
		Q.pop();
		for (int e = graph.head[u]; e != -1; e = graph.next[e]) {
			int v = graph.edges[e].v;
			int w = graph.edges[e].w;
			if (prev[v] == -1 && w > flow[u][v]) {
				prev[v] = u;
				Q.push(v);
			}
		}
	}
	return prev[sink] != -1;
}
