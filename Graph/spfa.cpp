// $O(kE)$, $k<2$ in normal
int dist[MAX_VERTEX];
bool visitied[MAX_VERTEX];
SPListGraph const & graph; // \SourceRef{source:graph}
void spfa(int source) {
	std::queue<int> queue;
	fill_range(dist, dist + graph.vertex_num, INF); // \SourceRef{source:utility}
	fill_range(visited, visited + graph.vertex_num, false);
	dist[source] = 0;
	queue.push(source);
	visited[source] = true;
	for (; !queue.empty(); ) {
		int u = queue.front();
		queue.pop();
		visited[u] = false;
		for (SPListGraph::Edge * edge = graph.head[u]; edge != NULL; edge = edge->next) {
			if (relax(u, edge->v, edge->w) && !visited[edge->v]) {
				queue.push(edge->v);
				visited[edge->v] = true;
			}
		}
	}
}
bool spfa_relax(int u, int v, int w) {
	if(dist[u] + w < dist[v]) {
		dist[v] = dist[u] + w;
		return true;
	}
	return false;
}
