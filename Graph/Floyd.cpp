// $\Theta\left(V^3\right)$
void Floyd(MatrixGraph const & graph, vector< vector<int> > & dist) {
	for (int vi=0; vi<graph.V; ++vi) {
		for (int vj=0; vj<graph.V; ++vj) {
			dist[vi][vj] = graph.edge(vi, vj);
		}
	}
	for (int vk=0; vk<graph.V; ++vk) {
		for (int vi=0; vi<graph.V; ++vi) {
			for (int vj=0; vj<graph.V; ++vj) {
				if (dist[vi][vk] + dist[vk][vj] < dist[vi][vj]) {
					dist[vi][vj] = dist[vi][vk] + dist[vk][vj];
				}
			}
		}
	}
}
