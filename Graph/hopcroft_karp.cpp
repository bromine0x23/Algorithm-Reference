// $O(\sqrt{V}E)$
BiGraph const & graph
std::vector<int> match_x, match_y;
std::vector<int> dist[MAX_N];
int dist_nil;
bool hopcroft_karp_bfs() {
	std::queue<int> queue;
	for (int x = 0; x < graph.x_num; ++x) {
		if (match_x[x] == -1) {
			dist[x] = 0;
			queue.push(x);
		} else {
			dist[x] = INF;
		}
	}
	dist_nil = INF;
	for (; !queue.empty(); ) {
		int x = queue.front();
		queue.pop();
		if (dist[x] < dist_nil) {
			for (int y = 0; y < graph.y_num; ++y) {
				if (graph.edge[x][y]) {
					if (match_y[y] != -1) {
						if (dist[match_y[y]] == INF) {
							dist[match_y[y]] = dist[x] + 1;
							queue.push(match_y[y]);
						}
					} else {
						if (dist_nil == INF) {
							dist_nil = dist[x] + 1;
						}
					}
				}
			}
		}
	}
	return dist_nil != INF;
}
bool hopcroft_karp_dfs(int x) {
	if (x != -1) {
		for (int y = 0; y < graph.y_num; ++y) {
			if (graph.edge[x][y]) {
				if (match_y[y] != -1) {
					if (dist[match_y[y]] == dist[x] + 1 && dfs(match_y[y])) {
						match_x[x] = y;
						match_y[y] = x;
						return true;
					}
				} else {
					if (dist_nil == dist[x] + 1) {
						match_x[x] = y;
						match_y[y] = x;
						return true;
					}
				}
			}
		}
		dist[x] = INF;
		return false;
	}
	return true;
}
int hopcroft_karp() {
	match_x = std::vector<int>(graph.x_num, -1);
	match_y = std::vector<int>(graph.y_num, -1);
	int match = 0;
	for (; hopcroft_karp_bfs(); ) {
		for (int x = 0; x < graph.x_num; ++x) {
			if (match_x[x] == -1) {
				if (dfs(x)) {
					++match;
				}
			}
		}
	}
	return match;
}
