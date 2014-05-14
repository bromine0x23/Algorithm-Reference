// $O(VE^2)$
ListGraph graph;
int flow[MAX_VERTEX][MAX_VERTEX];
int prev[MAX_VERTEX];
// find augmenting path by BFS
bool edmonds_karp_find(int source, int sink) {
	for (int i = 0; i < graph.vertex_num; ++i) {
		prev[i] = -1;
	}
	std::queue<int> queue;
	queue.push(source);
	for (; !queue.empty(); ) {
		int u = queue.front();
		queue.pop();
		for (int e = graph.head[u]; e != -1; e = graph.next[e]) {
			int v = graph.edges[e].v;
			int w = graph.edges[e].w;
			if (prev[v] == -1 && w > flow[u][v]) {
				prev[v] = u;
				queue.push(v);
			}
		}
	}
	return prev[sink] != -1;
}
int edmonds_karp(int source, int sink) {
	int max_flow = 0;
	for (int i = 0; i < graph.vertex_num; ++i) {
		for (int j = 0; j < graph.vertex_num; ++j) {
			flow[i][j] = 0;
		}
	}
	for (; edmonds_karp_find(source, sink); ) {
		max_flow += flow_update(sink);
	}
	return max_flow;
}
