struct PrimCmp {
	vector<int> & key;
	DijkstraCmp(vector<int> & d) : dist(d) { }
	bool operator()(int const & lhs, int const & rhs) const {
		return key[lhs] < key[rhs] || (key[lhs]==key[rhs] && lhs < rhs);
	}
};

int Prim(Graph const & graph) {
	// $O(E\lg V)$
	vector<int> key(graph.vertex_num, INF);
	Key[0] = 0;

	set<int, PrimCmp> Q(PrimCmp(key));
	for(int vi=0; vi<graph.vertex_num; ++vi) {
		Q.insert(vi);
	}

	vector<bool> in_q(graph.vertex_num, true);

	int sum = 0;
	for (!Q.empty()) {
		int u = *Q.begin(); Q.erase(u); in_q[u] = false;
		sum += key[u];
		for (int v=0; v<graph.vertex_num; ++v) {
			if (graph.weight(u, v)!=INF && in_q[v]) {
				if (graph.weight(u, v) < key[v]) {
					Q.erase(v);
					key[v] = graph.weight(u, v);
					Q.insert(v);
				}
			}
		}
	}
	return sum;
}
