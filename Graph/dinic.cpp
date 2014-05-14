// $O(V^2 E)$
// $\operatorname{dist}(v)$ is the length of the shortest path from $s$ to $v$ in $G_f$
// level graph of $G_f$ is $G_L=(V, E_L, c_f|_{E_L})$, where $E_L=\{(u,v)\in E_f : \operatorname{dist}(v) = \operatorname{dist}(u) + 1\}$£¬where $dist$
// A blocking flow is an $s-t$ flow $f'$ such that the graph $G' = (V, E_L', s, t)$ with $E_L' = \{(u,v) : f'(u,v) < c_f|_{E_L}(u,v)\}$ contains no $s-t$ path.
MatrixGraph graph; // $G = (V, E, c)$
int source, sink;
int flow[MAX_VERTEX][MAX_VERTEX];
int level[MAX_VERTEX]; // $\operatorname{dist}(v)$
// build $G_L$, using SPFA algorithm
bool dinic_build() {
	std::queue<int> queue;
	for (int i = 0; i < graph.V; ++i) {
		level[i] = 0;
	}
	queue.push(s);
	level[source] = 1;
	for (; !queue.empty(); ) {
		int u = queue.front();
		queue.pop();
		for (int v = 0; v < graph.V; ++v) {
			if (flow[u][v] > 0 && level[v] == 0) {
				level[v] = level[u] + 1;
				queue.push(v);
			}
		}
	}
	return level[sink] != 0;
}
// find $f'$ recursively
int dinic_find(int u, int cap) {
	if (u != sink) {
		int left_cap = cap;
		for (int v = 0; v < graph.V && left_cap != 0; ++v) {
			if (flow[u][v] > 0 && level[v] == level[u] + 1) {
				int f = dinic_find(v, minimum(left_cap, flow[u][v]));
				flow[u][v] -= f;
				flow[v][u] += f;
				left_cap -= f;
			}
		}
		cap -= left_cap;
	}
	return cap;
}
int dinic() {
	int ans = 0;
	for (int i = 0; i < graph.V; ++i) {
		for (int j = 0; j < graph.V; ++j) {
			flow[i][j] = graph.edge(u, v);
		}
	}
    for (; dinic_build(); ) {
		for (int flow; (flow = dinic_find(source, INF)) != 0; ) {
            ans += flow;
		}
	}
	return ans;
}
