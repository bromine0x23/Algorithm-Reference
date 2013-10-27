// $O(E\lg V)$
int Kruskal(vector<Edge> const & edges, int vertex_num, int edge_num) {
	sort(edges.begin(), edges.end());
	DisjointSet set(vertex_num);
	int sum = 0;
	for (int ei=0, vc=1; ei<edge_num && vc<vertex_num; ++ei) {
		if (set.find(edges[ei].u) != set.find(edges[ei].v)) {
			set.link(edges[ei].u, edges[ei].v);
			++vc;
			sum += edges[ei].w;
		}
	}
	return sum;
}
