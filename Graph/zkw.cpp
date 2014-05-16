struct Edge {
	int u, v;
	int capacity;
	int cost;
	int reverse; // index of edge $(v, u)$ which capacity is $-capacity$ and cost is $0$
};
ListGraph graph;
int source, sink;
int cost;
int answer;
int augment(int u, int flow) {
	if (u == sink) {
		answer += cost * flow;
	} else {
		visited[u] = true;
		int left_flow = flow;
		for (int e = graph.head[u]; e != -1 && left_flow > 0; e = graph.next[e]) {
			if(graph.edges[e].capacity > 0 && graph.edges[e].cost > 0 && !visited[graph.edges[e].v]) {
				int delta = augment(graph.edges[e].v, minimum(left_flow , graph.edges[e].capacity));
				graph.edges[e].capacity -= delta;
				graph.edges[graph.edges[e].reverse].capacity += delta;
				left_flow  -= delta;
			}
		}
		flow -= left_flow;
	}
	return flow;
}
bool relabel() {
	int delta = INF;
	for(int u = 0; u < graph.vertex_num; ++u) {
		if (visited[u]) {
			for (int e = graph.head[u]; e != -1; e = graph.next[e]) {
				if (graph.edges[e].capacity > 0 && !visited[graph.edges[e].v]) {
					update_minimum(delta, graph.edges[e].cost);
				}
			}
		}
	}
	if (delta != INF) {
		for(int u = 0; u < graph.vertex_num; ++u) {
			if (visited[u]) {
				for (int e = graph.head[u]; e != -1; e = graph.next[e]) {
					graph.edges[e].cost -= delta;
					graph.edges[graph.edges[e].reverse].cost += delta;
				}
			}
		}
		cost += delta;
		return true;
	} else {
		return false;
	}
}
void zkw_costflow() {
	answer = cost = 0;
	do {
		do {
			for (int v = 0; v < graph.vertex_num; ++v) {
				visited[v] = false;
			}
		} while (aug(source, INF) != 0);
	} while (relabel());
}
