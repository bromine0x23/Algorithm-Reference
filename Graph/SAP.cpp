MatrixGraph graph;
int S, T;
int flow[MAX_VERTEX][MAX_VERTEX];
int GAP[MAX_VERTEX], label[MAX_VERTEX];
int SAP() {
	int ans = 0;
	for (int i = 0; i < graph.V; ++i) {
		for (int j = 0; j < graph.V; ++j) {
			flow[i][j] = graph.edge(i, j);
		}
		label[i] = GAP[i] = 0;
	}
	for (GAP[0] = graph.V; label[S] < graph.V; ) {
		ans += SAP_find(S, INF);
	}
	return ans;
}
int SAP_find(int u, int cap) {
	if (u == T) {
		return cap;
	}
	int left_cap = cap, temp = V-1;
	for (int v=0; v<V; ++v) {
		if (flow[u][v] > 0 && label[u] == label[v]+1) {
			int f = SAP_find(v, minimum(delta, left_cap));
			left_cap -= f;
			flow[u][v] -= f;
			flow[v][u] += f;
			if (left_cap == 0 || label[S] == graph.V) {
				return cap - left_cap;
			}
		}
		if (flow[u][v] > 0) {
			update_minimum(temp, label[v]);
		}
	}
	if (cap == left_cap) {
		--GAP[label[u]];
		if (GAP[label[u]] == 0) {
			label[S] = graph.V;
		} else {
			label[u] = temp + 1;
			++GAP[label[u]];
		}
	}
	return cap - left_cap;
}
