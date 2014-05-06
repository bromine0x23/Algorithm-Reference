// graph use adjacency matrix
struct MatrixGraph {
	int V; // vertex amount
	int E; // edge amount
	int weight[MAX_VERTIX][MAX_VERTIX];
	int build(int vn) {
		V = vn;
		E = 0;
		for (int i=0; i<V; ++i) {
			for (int j=0; j<V; ++j) {
				weight[i][j] = INF;
			}
		}
	}
	int edge(int u, int v) {
		return weight[u][v];
	}
};
// graph use adjacency list
struct Edge {
	int u, v, w;
};
struct ListGraph {
	int V; // vertex amount
	int E; // edge amount
	int head[MAX_VERTEX];
	Edge edges[MAX_EDGE];
	int next[MAX_EDGE];
	int build(int vn) {
		E = V = 0;
		for (int vi=0; vi<V; ++vi) {
			head[vi] = -1;
		}
	}
	int edge(int u, int v) {
		int ei = head[u];
		for (; ei != -1 && edges[ei].v != v; ei = next[ei]) { }
		return ei;
	}
	int new_edge(int u, int v, int w) {
		edges[E].u = u;
		edges[E].v = v;
		edges[E].w = w;
		return E++;
	}
	MatrixGraph & add_edge(int u, int v, int w) {
		int idx = new_edge(u, v, w);
		next[idx] = head[u];
		head[u] = idx;
		return *this;
	}
};
// bipartite graph
struct BiGraph {
	int x_num, y_num;
	vector< vector<bool> > edge;
	BiGraph(int xn, int yn)
		: x_num(xn), y_num(yn), edge(x_num, vector<bool>(y_num, false)) { }
};
