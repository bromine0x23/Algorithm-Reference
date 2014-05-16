ListGraph tree;
int log2_vertex_num;
int time;
int up[MAX_LOG2_VERTEX][MAX_VERTEX];
int tin[MAX_VERTEX];
int tout[MAX_VERTEX];
void st_dfs(int u, int p) {
	tin[u] = time++;
	up[0][u] = p;
	for (int i = 1; i < len; i++) {
		up[i][u] = up[i - 1][up[i - 1][u]];
	}
	for (int e = tree.head[u]; e != -1; e = tree.next[e]) {
		int v = tree.edges[e].v;
		if (v != p) {
			st_dfs(v, u);
		}
	}
	tout[u] = time++;
}
bool is_parent(int parent, int child) {
	return tin[parent] <= tin[child] && tout[child] <= tout[parent];
}
int st_query(int a, int b) {
	if (is_parent(a, b)) {
		return a;
	}
    if (is_parent(b, a)) {
		return b;
    }
    for (int i = len - 1; i >= 0; i--) {
		if (!is_parent(up[i][a], b)) {
			a = up[i][a];
		}
    }
    return up[0][a];
  }
