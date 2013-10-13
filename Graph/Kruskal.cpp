// $O(E\lg V)$
int Kruskal(vector<Edge> const & edge, int vertex_num, int edge_num) {
	sort(edge.begin(), edge.end());
	DisjointSet set(vertex_num);
	int sum = 0;
	for (int ei=0, vc=1; ei<edge_num && vc<vertex_num; ++ei) {
		if (!set.same_set(edge[ei].u, edge[ei].v)) {
			set.link(edge[ei].u, edge[ei].v);
			++vc;
			sum += edge[ei].w;
		}
	}
	return sum;
}
