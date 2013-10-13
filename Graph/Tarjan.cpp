// $O(V)$
vector<int> DFS;
vector<int> low;
vector< vector<int> > component;
vector<int> component_id;
int index;

void Tarjan(Graph const & graph) {
	DFS	= vector<int>(graph.vertex_num, -1);
	low = vector<int>(graph.vertex_num, -1);
	component = vector< vector<int> >(graph.vertex_num, vector<int>());
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
	Graph const & graph,
	int & index,
	stack<int> & S,
	vector<bool> & in_s,
	int u
) {
	DFN[u] = low[u] = index++;
	S.push(u);
	in_s[i] = true;
    for (int v=0; v < graph.vertex_num; ++v) {
	    if (graph.has_edge(u, v)) {
		    if (DFN[v] == -1) {
			    Tarjan_main(graph, S, in_s, v);
			    low[u] = min_val(low[u], low[v]);
		    } else if (in_s[v]) {
		    	low[u] = min_val(low[u], DFN[v]);
		    }
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
