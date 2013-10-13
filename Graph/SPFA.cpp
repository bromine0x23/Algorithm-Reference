// $O\left(kE\right)$, $k<2$ in normal
vector<int> SPFA(Graph const & graph, int source) {
	vector<int> dist(graph.vertex_num, INF);
	vector<bool> in_queue(graph.vertex_num, false);

	queue<int> Q;

	Q.push(source);
	dist[source] = 0;
	in_queue[source] = true;

	while (!Q.empty()) {
		int u = Q.front(); Q.pop(); in_queue[u] = false;
		for (int v = 0; v<graph.vertex_num; ++v) { // $\forall (u,v)\in E[G]$
			if (relax(dist, u, v, graph.edge(u, v)) && !in_queue[v]) {
				in_queue[v] = true;
				Q.push(v);
			}
		}
	}
	return dist;
}

bool relax(vector<int> & dist, int u, int v, int w) {
	if(dist[u] + w < dist[v]) {
		dist[v] = dist[u] + w;
		return true;
	}
	return false;
}
