// $O(VE)$
BiGraph graph;
std::vector<int> match_x, match_y;
std::vector<bool> visited;
bool hungarian_dfs(int x) {
	for(int y = 0; y < graph.y_num; ++y) {
		if (graph.edge[x][y] && !visited[y]) {
			visited[y] = true;
			if (match_y[y] == -1 || Hungarian_DFS(match_y[y])) {
				match_x[x] = y;
				match_y[y] = x;
				return true;
			}
		}
	}
	return false;
}

int hungarian() {
	match_x = std::vector<int>(graph.x_num, -1);
	match_y = std::vector<int>(graph.y_num, -1);
	int match = 0;
	for (int x = 0; x < graph.x_num; ++x) {
		if (match_x[x] == -1) {
			visited = std::vector<bool>(graph.y_num, false);
			if (hungarian_dfs(x)) {
				++match;
			}
		}
	}
	return match;
}
