// $O(E|f|)$, $f$ is max flow value
ListGraph graph;
int flow[MAX_VERTEX][MAX_VERTEX];
int prev[MAX_VERTEX];
// find augmenting path by DFS
bool ford_fulkerson_find(int u, int sink) {
	if (u != sink) {
		for (int e = graph.head[u]; e != -1; e = graph.next[e]) {
			int v = graph.edges[e].v;
			int w = graph.edges[e].w;
			if (prev[v] == -1 && w > flow[u][v]) {
				prev[v] = u;
				if (ford_fulkerson_find(v, sink)) {
					return true;
				}
			}
		}
		return false;
	} else {
		return true;
	}
}
int ford_fulkerson(int source, int sink) {
	int max_flow = 0;
	for (int i = 0; i < graph.vertex_num; ++i) {
		for (int j = 0; j < graph.vertex_num; ++j) {
			flow[i][j] = 0;
		}
	}
	for (; ; ) {
		for (int i = 0; i < graph.vertex_num; ++i) {
			prev[i] = -1;
		}
		if (!ford_fulkerson_find(source, sink)) {
			break;
		}
		max_flow += flow_update(sink);
	}
	return max_flow;
}