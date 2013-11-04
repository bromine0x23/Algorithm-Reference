// adjacency list: $\Theta(V+E)$, adjacency matrix: $O(V^2)$
ListGraph graph; // $G = \{V, E\}$
ListGraph rev_graph; // $G_r = \{V, \{(u, v)|(v, u)\in E\}\}$
int order[MAX_VERTEX], order_count; // vertex order in DFS
bool visited[MAX_VERTEX];
int component[MAX_VERTEX], component_number;
void Kosaraju() {
	memset(visited, 0, sizeof(visited[0])*graph.V);
	order_count = 0;
	for (int v=0; v<graph.V; ++v) {
		if (!visited[v]) { Kosaraju_DFS(v); }
	}
	memset(visited, 0, sizeof(visited[0])*graph.V);
	component_number = 0;
	for (int i=order_count-1; i>=0; --i) {
		if (!visited[order[i]]) { Kosaraju_RDFS(order[i]); ++component_number; }
	}
}
void Kosaraju_DFS(int v) {
	visited[v] = true;
	for (int e = graph.head[v]; e != -1; e = graph.next[e]) {
		if (!visited[graph.edge[e].v]) { Kosaraju_DFS(graph.edge[e].v); }
	}
	order[order_count++] = v;
}
void Kosaraju_RDFS(int v) {
	visited[v] = true;
	component[v] = component_number;
	for (int e = rev_graph.head[v]; e != -1; e = rev_graph.next[e]) {
		if (!visited[rev_graph.edge[e].v]) { Kosaraju_RDFS(rev_graph.edge[e].v); }
	}
}
