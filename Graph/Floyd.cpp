// $\Theta\left(V^3\right)$
void Floyd(MatrixGraph const & graph, vector< vector<int> > & dist) {
	for (int vi=0; vi<graph.vertex_num; ++vi) {
		for (int vj=0; vj<graph.vertex_num; ++vj) {
			dist[vi][vj] = graph.edge(vi, vj);
		}
	}
	for (int vk=0; vk<graph.vertex_num; ++vk) {
		for (int vi=0; vi<graph.vertex_num; ++vi) {
			for (int vj=0; vj<graph.vertex_num; ++vj) {
				if (dist[vi][vk] + dist[vk][vj] < dist[vi][vj]) {
					dist[vi][vj] = dist[vi][vk] + dist[vk][vj];
				}
			}
		}
	}
}
