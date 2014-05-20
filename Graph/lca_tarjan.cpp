// $O(V)$
ListGraph tree;
std::vector<Edge> queries;
void tarjan_main(int u){
	ancestor[u] = u;
	for (int e = tree.head[u]; e != -1; e = tree.next[e]) {
		int v = tree.edges[e].v;
		tarjan_main(v);
		set.link(u, v);
		ancestor[set.find(u)] = u;
	}
	visitied[u] = true;
	for (int i = 0; i < queries.size(); ++i) {
		if (vistied[queries[i].v]) {
			queries[i].w = ancestor[set.find(v)]; // $\operatorname{LCA}(u, v)$
		}
	}
}
void tarjan() {
	set = DisjointSet(tree.vertex_num);
	for (int v = 0; v < tree.vertex_num; ++v) {
		if (tree.next[e][tree.head[v]] == -1) {
			// $v$ is a root of a tree
			tarjan_main(v);
		}
	}
}
