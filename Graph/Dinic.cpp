// $O(V^2E)$
MatrixGraph graph;
int S, T;
int flow[MAX_VERTEX][MAX_VERTEX];
int level[MAX_VERTEX];
int Dinic() {
	int ans = 0;
	for (int i = 0; i < graph.V; ++i) {
		for (int j = 0; j < graph.V; ++j) {
			flow[i][j] = graph.edge(u, v);
		}
	}
    for (; Dinic_BFS(); ) {
		for (int flow; (flow = Dinic_DFS(S, INF)) != 0; ) {
            ans += flow;
		}
	}
	return ans;
}
bool Dinic_BFS() {
	queue<int> Q;
	for (int i=0; i<graph.V; ++i) {
		level[i] = 0;
	}
	Q.push(S);
	level[S] = 1;
	for (; !Q.empty(); ) {
        int u = Q.front();
        Q.pop();
        for (int v = 0; v < Graph.V; ++v) {
            if (flow[u][v] > 0 && level[v] == 0) {
				level[v] = level[u] + 1;
				Q.push(v);
			}
		}
    }
	return level[T] != 0;
}
int Dinic_DFS(int u, int cap) {
	if (u == T) {
		return cap;
	}
	int left_cap = cap;
	for (int v = 0; v < graph.V && left_cap != 0; ++v) {
		if (flow[u][v] > 0 && level[v] == level[u]+1) {
			int f = Dinic_DFS(v, minimum(left_cap, flow[u][v]));
			left_cap -= f;
			flow[u][v] -= f;
			flow[v][u] += f;
		}
	}
	return cap - left_cap;
}
