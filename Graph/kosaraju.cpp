// adjacency list: $\Theta(V+E)$, adjacency matrix: $O(V^2)$
ListGraph graph; // $G = \{V, E\}$
ListGraph graph_reverse; // $G_r = \{V, \{(u, v)|(v, u)\in E\}\}$
int order[MAX_VERTEX], order_count; // vertex order in DFS
bool visited[MAX_VERTEX];
int component[MAX_VERTEX], component_number;
void kosaraju_dfs(int v) {
	visited[v] = true;
	for (int e = graph.head[v]; e != -1; e = graph.next[e]) {
		if (!visited[graph.edge[e].v]) {
			kosaraju_dfs(graph.edge[e].v);
		}
	}
	order[order_count++] = v;
}
void kosaraju_dfs_reverse(int v) {
	visited[v] = true;
	component[v] = component_number;
	for (int e = graph_reverse.head[v]; e != -1; e = graph_reverse.next[e]) {
		if (!visited[graph_reverse.edge[e].v]) {
			kosaraju_dfs_reverse(graph_reverse.edge[e].v);
		}
	}
}
void kosaraju() {
	for (int i = 0; i < graph.vertex_num; ++i) {
		visited[i] = false;
	}
	order_count = 0;
	for (int v = 0; v < graph.vertex_num; ++v) {
		if (!visited[v]) {
			kosaraju_dfs(v);
		}
	}
	for (int i = 0; i < graph.vertex_num; ++i) {
		visited[i] = false;
	}
	component_number = 0;
	for (int i = order_count - 1; i >= 0; --i) {
		if (!visited[order[i]]) {
			kosaraju_dfs_reverse(order[i]);
			++component_number;
		}
	}
}
