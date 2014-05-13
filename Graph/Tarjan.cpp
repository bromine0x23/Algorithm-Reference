// $O(V+E)$
ListGraph graph;
int DFN[MAX_VERTEX]; // order in DFS
int low[MAX_VERTEX];
int index;
std::stack<int> S; bool in_s[MAX_VERTEX];
int component[MAX_VERTEX], component_number;
void Tarjan() {
	memset(DFN, -1, sizeof(DFN[0])*graph.V);
	memset(low, -1, sizeof(low[0])*graph.V);
	memset(in_s, 0, sizeof(in_s[0])*graph.V);
	component_number = 0; index = 0; S.clear();
	for (int v = 0; v < graph.V; ++v) {
		if (DFN[v] == -1) {
			Tarjan_main(u);
		}
	}
}
void Tarjan_main(int u) {
	low[u] = DFN[u] = index++;
	S.push(u);
	in_s[i] = true;
	for (int e = graph.head[u]; e != -1; e = graph.next[e]) {
		int v = graph.edges[e].v;
		if (DFN[v] == -1) {
			Tarjan_main(v);
			update_minimum(low[u], low[v]);
		} else if (in_s[v]) {
			update_minimum(low[u], DFN[v]);
		}
    }
    if (DFN[u] == low[u]) {
	    int v;
	    do {
	    	v = S.top();
	    	S.pop();
	    	in_s[v] = false;
			component[v] = component_number;
	    } (u != v);
	    ++component_number;
    }
}
