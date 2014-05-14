// $\Theta(V^3)$
MatrixGraph graph;
int dist[MAX_VERTEX][MAX_VERTEX];
void floyd() {
	for (int vi = 0; vi < graph.vertex_num; ++vi) {
		for (int vj = 0; vj < graph.vertex_num; ++vj) {
			dist[vi][vj] = graph.edge(vi, vj);
		}
	}
	for (int vk = 0; vk < graph.vertex_num; ++vk) {
		for (int vi = 0; vi < graph.vertex_num; ++vi) {
			for (int vj = 0; vj < graph.vertex_num; ++vj) {
				if (vi != vj) {
					update_minimum(dist[vi][vj], dist[vi][vk] + dist[vk][vj]);
				}
			}
		}
	}
}
