// $O(E|f|)$, $f$ is max flow value
MFListGraph graph; // \SourceRef{source:graph}
int source, sink;
bool visited[MAX_VERTEX];
// find augmenting path by DFS
int ford_fulkerson_find(int u, \int capacity) {
	int flow;
	if (u != sink) {
		flow = 0;
		visited[u] = true;
		for (MFEdge * edge = graph.head[u]; edge != NULL && flow < capacity; edge = edge->next) {
			if (edge->flow < edge->capacity && !visited[edge->v]) {
				int use_flow = ford_fulkerson_find(edge->v, minimum(capacity - flow, edge->capacity - edge->flow));
				flow += use_flow;
				edge->flow += use_flow;
				edge->reverse->flow -= use_flow;
			}
		}
	} else {
		flow = capacity;
	}
	return flow;
}
int ford_fulkerson() {
	int max_flow = 0;
	for (int flow = INF; flow > 0; ) {
		fill_range(visited, visited + graph.vertex_num, false); // \SourceRef{source:utility}
		flow = ford_fulkerson_find(source, INF);
		max_flow += flow;
	}
	return max_flow;
}
