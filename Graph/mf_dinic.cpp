// $O(V^2 E)$
// $\operatorname{dist}(v)$ is the length of the shortest path from $s$ to $v$ in $G_f$
// level graph of $G_f$ is $G_L=(V, E_L, c_f|_{E_L})$, where $E_L=\{(u,v)\in E_f : \operatorname{dist}(v) = \operatorname{dist}(u) + 1\}$
// A blocking flow is an $s-t$ flow $f'$ such that the graph $G' = (V, E_L', s, t)$ with $E_L' = \{(u,v) : f'(u,v) < c_f|_{E_L}(u,v)\}$ contains no $s-t$ path.
MFListGraph graph; // $G = (V, E, c)$, \SourceRef{source:graph}
int source, sink;
int level[MAX_VERTEX]; // $\operatorname{dist}(v)$
// build $G_L$, using SPFA algorithm
bool dinic_build() {
	std::queue<int> queue;
	fill_range(level, level + graph.vertex_num, 0); // \SourceRef{source:utility}
	queue.push(source);
	level[source] = 1;
	for (; !queue.empty(); ) {
		int u = queue.front();
		queue.pop();
		for (MFEdge * edge = graph.head[u]; edge != NULL; edge = edge->next) {
			if (edge->flow < edge->capacity && level[edge->v] == 0) {
				level[edge->v] = level[edge->u] + 1;
				queue.push(edge->v);
			}
		}
	}
	return level[sink] != 0;
}
// find $f'$ recursively
int dinic_find(int u, int capacity) {
	int flow;
	if (u != sink) {
		flow = 0;
		for (MFEdge * edge = graph.head[u]; edge != NULL && flow < capacity; edge = edge->next) {
			if (edge->flow < edge->capacity && level[edge->v] == level[edge->u] + 1) {
				int use_flow = dinic_find(edge->v, minimum(capacity - flow, edge->capacity - edge->flow));
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
int dinic() {
	int max_flow = 0;
	for (; dinic_build(); ) {
		for (int flow; flow = dinic_find(source, INF), flow != 0; ) {
			max_flow += flow;
		}
	}
	return max_flow;
}
