// $O(kE)$, $k<2$ in normal
SPListGraph const & graph; // \SourceRef{source:graph}
int dist[MAX_VERTEX];
int prev[MAX_VERTEX];
SPEdge * path[MAX_VERTEX];
bool in_queue[MAX_VERTEX];
void spfa(int source) {
	std::queue<int> queue;
	fill_range(dist, dist + graph.vertex_num, INF); // \SourceRef{source:utility}
	fill_range(prev, prev + graph.vertex_num, -1);
	fill_range<SPEdge *>(path, path + graph.vertex_num, NULL);
	fill_range(in_queue, in_queue + graph.vertex_num, false);
	dist[source] = 0;
	queue.push(source);
	in_queue[source] = true;
	for (; !queue.empty(); ) {
		int u = queue.front();
		queue.pop();
		in_queue[u] = false;
		for (SPEdge * edge = graph.head[u]; edge != NULL; edge = edge->next) {
			if (dist[edge->u] + edge->w < dist[edge->v]) {
				dist[edge->v] = dist[edge->u] + edge->w;
				path[edge->v] = edge;
				prev[edge->v] = edge->u;
				if (!in_queue[edge->v]) {
					// SLF(Small Label First) Optimize: let \verb"h = queue.front()", $v$ push front when $dist_{h} \leqslant dist_{v}$
					queue.push(edge->v);
					in_queue[edge->v] = true;
				}
			}
		}
	}
}
