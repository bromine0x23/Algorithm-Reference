// $O(V^2 E)$
MatrixGraph graph;
int source, sink;
int flow[MAX_VERTEX][MAX_VERTEX];
int label[MAX_VERTEX];
int GAP[MAX_VERTEX];
int sap_find(int u, int cap) {
	if (u != sink) {
		int left_cap = cap, temp = graph.vertex_num - 1;
		for (int v = 0; v < graph.vertex_num; ++v) {
			if (flow[u][v] > 0 && label[u] == label[v]+1) {
				int f = sap_find(v, minimum(delta, left_cap));
				left_cap -= f;
				flow[u][v] -= f;
				flow[v][u] += f;
				if (left_cap == 0 || label[source] == graph.vertex_num) {
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
				label[source] = graph.vertex_num;
			} else {
				label[u] = temp + 1;
				++GAP[label[u]];
			}
		}
		cap -= left_cap;
	}
	return cap;
}
int sap() {
	int max_flow = 0;
	for (int i = 0; i < graph.vertex_num; ++i) {
		for (int j = 0; j < graph.vertex_num; ++j) {
			flow[i][j] = graph.edge(i, j);
		}
		label[i] = GAP[i] = 0;
	}
	GAP[0] = graph.vertex_num;
	for (; label[source] < graph.vertex_num; ) {
		max_flow += sap_find(source, INF);
	}
	return max_flow;
}
