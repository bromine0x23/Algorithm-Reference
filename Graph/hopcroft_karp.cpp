// $O(\sqrt{V}E)$
BiGraph const & graph
std::vector<int> match_x, match_y;
std::vector<int> dist_x, dist_y;
std::vector<bool> visited;
int dist_nil;
bool hopcroft_karp_bfs() {
	dist_x = std::vector<int>(graph.x_num, INF);
	dist_y = std::vector<int>(graph.y_num, INF);
	std::queue<int> queue;
	for (int x = 0; x < graph.x_num; ++x) {
		if (match_x[x] == -1) {
			dist_x[x] = 0;
			queue.push(x);
		}
	}
	for (dist_nil = INF; !queue.empty(); ) {
		int x = queue.front();
		queue.pop();
		if (dist[x] < dist_nil) {
			for (int y = 0; y < graph.y_num; ++y) {
				if (dist[y] == INF) {
					dist_y[y] = dist_x[x] + 1;
					if (match_y[y] != -1) {
						dist_x[match_y[y]] = dist_y[y] + 1;
						queue.push(match_y[y]);
					} else {
						dist_nil = dist_y[y];
					}
				}
			}
		}
	}
	return dist_nil != INF;
}
bool hopcroft_karp_dfs(int x) {
	for (int y = 0; y < graph.y_num; ++y) {
		if(!visited[y] && dist_y[y] == dist_x[x] + 1) {
			visited[y] = true;
			if(match_y[y] == -1 || hopcroft_karp_dfs(match_y[v])) {
				match_x[x] = y;
				match_y[y] = x;
				return true;
			}
		}
	}
}
int hopcroft_karp() {
	match_x = std::vector<int>(graph.x_num, -1);
	match_y = std::vector<int>(graph.y_num, -1);
	int match = 0;
	for (; hopcroft_karp_bfs(); ) {
		visited = std::vector<bool>(graph.y_num, false);
		for (int x = 0; x < graph.x_num; ++x) {
			if (match_x[x] == -1 && hopcroft_karp_dfs(x)) {
				++match;
			}
		}
	}
	return match;
}
