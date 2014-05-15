ListGraph graph; // actually a tree or forest
std::vector<Edge> queries;
void tarjan_main(int u){
	ancestor[u] = u;
	for (int e = graph.head[u]; e != -1; e = graph.next[e] ) {
		tarjan_main(graph.edges[e].v);
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
	set = DisjointSet(graph.vertex_num);
	for (int v = 0; v < graph.vertex_num; ++v) {
		if (graph.next[e][graph.head[v]] == -1) {
			// $v$ is a root of a tree
			tarjan_main(v);
		}
	}
}
