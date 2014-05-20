// \SourceRef{source:spfa}
MCFListGraph const & graph; // \SourceRef{source:graph}
int source, sink;
int cost[MAX_VERTEX];
int prev[MAX_VERTEX];
MCFEdge * path[MAX_VERTEX];
bool in_queue[MAX_VERTEX];
bool find_spfa() {
	std::queue<int> queue;
	fill_range(cost, cost + graph.vertex_num, INF); // \SourceRef{source:utility}
	fill_range(prev, prev + graph.vertex_num, -1);
	fill_range<SPEdge *>(path, path + graph.vertex_num, NULL);
	fill_range(in_queue, in_queue + graph.vertex_num, false);
	cost[source] = 0;
	queue.push(source);
	in_queue[source] = true;
	for (; !queue.empty(); ) {
		int u = queue.front();
		queue.pop();
		in_queue[u] = false;
		for (MCFEdge * edge = graph.head[u]; edge != NULL; edge = edge->next) {
			if (edge->flow < edge->capacity && cost[edge->u] + edge->cost < cost[edge->v]) {
				cost[edge->v] = cost[edge->u] + edge->cost;
				prev[edge->v] = edge->u;
				path[edge->v] = edge;
				if (!in_queue[edge->v]) {
					queue.push(edge->v);
					in_queue[edge->v] = true;
				}
			}
		}
	}
	return cost[sink] != INF;
}
int mcf_spfa() {
	int min_cost_flow = 0;
	for (; find_spfa(); ) {
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
