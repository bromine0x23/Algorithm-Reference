// \SourceRef{source:dijkstra}
MFListGraph const & graph; // \SourceRef{source:graph}
int source, sink;
int prev[MAX_VERTEX];
MFEdge * path[MAX_VERTEX];
bool edmonds_karp_find() {
	std::queue<int> queue;
	fill_range(prev, prev + graph.vertex_num, -1); // \SourceRef{source:utility}
	fill_range<Edge *>(path, path + graph.vertex_num, NULL);
	queue.push(source);
	visited[source] = true;
	for (; !queue.empty(); ) {
		int u = queue.front();
		queue.pop();
		for (Edge * edge = graph.head[u]; edge != NULL; edge = edge->next) {
			if (edge->flow < edge->capacity && prev[edge->v] == -1) {
				queue.push(edge->v);
				prev[edge->v] = edge->u;
				path[edge->v] = edge;
			}
		}
	}
	return prev[sink] != -1;
}
int edmonds_karp() {
	int max_flow = 0;
	for (; edmonds_karp_find(); ) {
		int flow = INF;
		for (int v = sink; prev[v] != -1; v = prev[v]) {
			update_minimum(flow, path[v]->capacity - path[v]->flow);
		}
		for (int v = sink; prev[v] != -1; v = prev[v]) {
			path[v]->flow += flow;
			path[v]->reverse->flow -= flow;
		}
		min_cost_flow += flow;
	}
	return max_flow;
}
