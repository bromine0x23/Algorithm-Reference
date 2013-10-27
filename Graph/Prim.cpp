struct PrimCmp {
	vector<int> & key;
	DijkstraCmp(vector<int> & K) : key(K) { }
	bool operator()(int const & lhs, int const & rhs) const {
		return key[lhs] < key[rhs] || (key[lhs]==key[rhs] && lhs < rhs);
	}
};
// $O(E\lg V)$
int Prim(ListGraph const & graph) {
	vector<int> key(graph.vertex_num, INF); Key[0] = 0;
	set<int, PrimCmp> Q(PrimCmp(key));
	for(int vi=0; vi<graph.vertex_num; ++vi) { Q.insert(vi); }
	vector<bool> in_q(graph.vertex_num, true);
	int sum = 0;
	for (; !Q.empty(); ) {
		int u = *Q.begin(); Q.erase(u); in_q[u] = false;
		sum += key[u];
		for (int e = graph.head[u]; e != -1; e = graph.next[e] ) {
			int v = graph.edges[e].v, w = graph.edges[e].w;
			if (in_q[v] && w < key[v]) {
				Q.erase(v); key[v] = w; Q.insert(v);
			}
		}
	}
	return sum;
}
