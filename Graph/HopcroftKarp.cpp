BiGraph graph;
vector<int> match_x;
vector<int> match_y;
vector<int> dist_x;
vector<int> dist_y;
vector<bool> visited;
int dist_nil;

int HopcroftKarp() {
	match_x = vector<int>(graph.x_num, -1);
	match_y = vector<int>(graph.y_num, -1);
	int match = 0;

	while (HopcroftKarp_BFS()) {
		visited = vector<bool>(graph.y_num, false);
		for (int x=0; x<graph.x_num; ++x) {
			if (match_x[x] == -1 && HopcroftKarp_DFS(x)) {
				++match;
			}
		}
	}

	return match;
}

bool HopcroftKarp_BFS() {
	dist_x = vector<int>(graph.x_num, INF);
	dist_y = vector<int>(graph.y_num, INF);
	queue<int> Q;

	for (int x=0; x<graph.x_num; ++x) {
		if (match_x[x] == -1) {
			dist_x[x] = 0;
			Q.push(x);
		}
	}

	dist_nil = INF;
	while (!Q.empty()) {
		int x = Q.front();
		Q.pop();

		if (dist[x] < dist_nil) {
			for (int y=0; y<graph.y_num; ++y) {
				if (dist[y] == INF) {
					dist_y[y]] = dist_x[x] + 1;
					if (match_y[y] != -1) {
						dist_x[match_y[y]] = dist_y[y] + 1;
						Q.push(match_y[y]);
					} else {
						dist_nil = dist_y[y];
					}
				}
			}
		}
	}

	return dist_nil != INF;
}

bool HopcroftKarp_DFS(int x) {
	for (int y=0; y<graph.y_num; ++y) {
		if(!visited[y] && dist_y[y] == dist_x[x] + 1) {
			visited[y] = true;
            if(match_y[y] == -1 || HopcroftKarp_DFS(match_y[v]))
            {
                match_x[x] = y;
				match_y[y] = x;
				return true;
            }
        }
	}
}
