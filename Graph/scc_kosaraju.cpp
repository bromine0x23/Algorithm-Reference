// adjacency list: $\Theta(V+E)$, adjacency matrix: $O(V^2)$
BasicListGraph graph; // $G = \{V, E\}$, \SourceRef{source:graph}
BasicListGraph graph_reverse; // $G_r = \{V, \{(u, v)|(v, u)\in E\}\}$
int order[MAX_VERTEX], order_count; // vertex order in DFS
bool visited[MAX_VERTEX];
int component[MAX_VERTEX], component_number;
void kosaraju_dfs(int v) {
	visited[v] = true;
	for (BasicEdge * edge = graph.head[u]; edge != NULL; edge = edge->next) {
		if (!visited[edge->v]) {
			kosaraju_dfs(edge->v);
		}
	}
	order[order_count++] = v;
}
void kosaraju_dfs_reverse(int v) {
	visited[v] = true;
	component[v] = component_number;
	for (BasicEdge * edge = graph_reverse.head[u]; edge != NULL; edge = edge->next) {
		if (!visited[edge->v]) {
			kosaraju_dfs_reverse(edge->v);
		}
	}
}
void kosaraju() {
	fill_range(visited, visited + graph.vertex_num, false); // \SourceRef{source:utility}
	order_count = 0;
	for (int v = 0; v < graph.vertex_num; ++v) {
		if (!visited[v]) {
			kosaraju_dfs(v);
		}
	}
	fill_range(visited, visited + graph_reverse.vertex_num, false);
	component_number = 0;
	for (int i = order_count - 1; i >= 0; --i) {
		if (!visited[order[i]]) {
			kosaraju_dfs_reverse(order[i]);
			++component_number;
		}
	}
}
