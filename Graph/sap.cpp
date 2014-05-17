// $O(V^2 E)$
MFListGraph graph; // \SourceRef{source:graph}
int source, sink;
int high[MAX_VERTEX];
int gap[MAX_VERTEX];
int sap_find(int u, int capacity) {
	int flow;
	if (u != sink) {
		flow = 0;
		int min_high = vertex_num - 1;
		for (MFEdge * edge = graph.head[u]; edge != NULL && flow < capacity && high[source] < graph.vertex_num; edge = edge->next) {
			if (edge->flow < edge->capacity) {
				if (high[u] == high[edge->v] + 1) {
					int use_flow = sap_find(edge->v, minimum(capacity - flow, edge->capacity - edge->flow));
					flow += use_flow;
					edge->flow += use_flow;
					edge->reverse->flow -= use_flow;
				}
				update_minimum(min_high, high[edge->v]);
			}
		}
		if (flow == 0) {
			--gap[high[u]];
			if (gap[high[u]] != 0) {
				high[u] = min_high + 1;
				++gap[high[u]];
			} else {
				high[source] = graph.vertex_num;
			}
		}
	} else {
		flow = capacity;
	}
	return flow;
}
int sap() {
	int max_flow = 0;
	fill_range(high, high + graph.vertex_num, 0); // \SourceRef{source:utility}
	fill_range(gap, gap + graph.vertex_num, 0);
	gap[0] = graph.vertex_num;
	for (; high[source] < graph.vertex_num; ) {
		max_flow += sap_find(source, INF);
	}
	return max_flow;
}
