// \SourceRef{source:dijkstra}
MCFListGraph const & graph; // \SourceRef{source:graph}
int source, sink;
int cost[MAX_VERTEX];
int prev[MAX_VERTEX];
MCFEdge * path[MAX_VERTEX];
bool find_dijkstra() {
	fill_range(cost, cost + graph.vertex_num, INF); // \SourceRef{source:utility}
	fill_range(prev, prev + graph.vertex_num, -1);
	fill_range<Edge *>(path, path + graph.vertex_num, NULL);
	cost[source] = 0;
	std::set<int, bool(*)(int ,int)> queue(dijkstra_compare);
	for (int vi = 0; vi < graph.vertex_num; ++vi) {
		queue.insert(vi);
	}
	for (; !queue.empty(); ) {
		int u = *queue.begin();
		queue.erase(u);
		for (Edge * edge = graph.head[u]; edge != NULL; edge = edge->next) {
			if (queue.count(edge->v) > 0 && edge->flow < edge->capacity && cost[edge->u] + edge->cost < cost[edge->v]) {
				queue.erase(edge->v);
				cost[edge->v] = cost[edge->u] + edge->cost;
				prev[edge->v] = edge->u;
				path[edge->v] = edge;
				queue.insert(edge->v);
			}
		}
	}
	return cost[sink] != INF;
}
int mcf_dijkstra() {
	int min_cost_flow = 0;
	for (; find_dijkstra(); ) {
		int flow = INF;
		for (int v = sink; prev[v] != -1; v = prev[v]) {
			update_minimum(flow, path[v]->capacity - path[v]->flow);
		}
		for (int v = sink; prev[v] != -1; v = prev[v]) {
			path[v]->flow += flow;
			path[v]->reverse->flow -= flow;
		}
		min_cost_flow += cost[sink] * flow;
	}
	return min_cost_flow;
}
