// adjacency matrix : $O(V^2)$
// binary heap + adjacency list : $O(E \log V)$
// Fibonacci heap + adjacency list: $O(E + V \log V)$
int dist[MAX_VERTEX];
int prev[MAX_VERTEX];
Edge * path[MAX_VERTEX];
SPListGraph const & graph; // \SourceRef{source:graph}
bool dijkstra_compare(int lhs, int rhs) {
	return dist[lhs] < dist[rhs] || (dist[lhs] == dist[rhs] && lhs < rhs);
}
void dijkstra(int source) {
	fill_range(dist, dist + graph.vertex_num, INF); // \SourceRef{source:utility}
	fill_range(prev, prev + graph.vertex_num, -1);
	fill_range<Edge *>(path, path + graph.vertex_num, NULL);
	dist[source] = 0;
	std::set<int, bool(*)(int ,int)> queue(dijkstra_compare); // use binary heap
	for (int vi = 0; vi < graph.vertex_num; ++vi) {
		queue.insert(vi);
	}
	for (; !queue.empty(); ) {
		int u = *queue.begin();
		queue.erase(u);
		for (SPEdge * edge = graph.head[u]; edge != NULL; edge = edge->next) {
			if (queue.count(edge->v) > 0 && dist[edge->u] + edge->w < dist[edge->v]) {
				queue.erase(edge->v);
				dist[edge->v] = dist[edge->u] + edge->w;
				prev[edge->v] = edge->u;
				path[edge->v] = edge;
				queue.insert(edge->v);
			}
		}
	}
}
