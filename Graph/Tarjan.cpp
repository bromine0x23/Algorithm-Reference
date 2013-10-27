// $O(V)$
vector<int> DFS;
vector<int> low;
vector< vector<int> > component;
vector<int> component_id;
int index;
void Tarjan(ListGraph const & graph) {
	DFS	= vector<int>(graph.vertex_num, -1);
	low = vector<int>(graph.vertex_num, -1);
	component = vector< vector<int> >(graph.vertex_num);
	component_id = vector<int>(graph.vertex_num);
	index = 0;
	for(int u=0; u < graph.vertex_num; ++u) {
		if (DFN[u] == -1) {
			stack<int> S;
			vector<bool> in_s(graph.vertex_num, false);
			Tarjan_main(graph, S, in_s, u);
		}
	}
}
void Tarjan_main(
	ListGraph const & graph,
	int & index,
	stack<int> & S,
	vector<bool> & in_s,
	int u
) {
	DFN[u] = low[u] = index++;
	S.push(u);
	in_s[i] = true;
	for (int e = graph.head[u]; e != -1; e = graph.next[e]) {
		int v = graph.edges[e].v;
		if (DFN[v] == -1) {
			Tarjan_main(graph, S, in_s, v);
			min_by_ref(low[u], low[v]);
		} else if (in_s[v]) {
			min_by_ref(low[u], DFN[v]);
		}
    }
    if (DFN[u] == low[u]) {
	    ++component_number;
	    int v;
	    do {
	    	v = S.top();
			S.pop();
			in_s[v] = false;
			component[component_number].push_back(j);
			component_id[v] = component_number;
	    } (u != v);
    }
}
