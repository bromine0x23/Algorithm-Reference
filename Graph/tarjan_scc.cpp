// $O(V+E)$
BasicListGraph graph;
int DFN[MAX_VERTEX]; // order in DFS
int low[MAX_VERTEX];
int index;
std::stack<int> stack;
bool in_stack[MAX_VERTEX];
int component[MAX_VERTEX], component_number;
void tarjan_main(int u) {
	low[u] = DFN[u] = index++;
	stack.push(u);
	in_stack[i] = true;
	for (BasicEdge * edge = graph.head[u]; edge != NULL; edge = edge->next) {
		if (DFN[edge->v] == -1) {
			tarjan_main(edge->v);
			update_minimum(low[u], low[edge->v]);
		} else if (in_s[edge->v]) {
			update_minimum(low[u], DFN[edge->v]);
		}
	}
    if (DFN[u] == low[u]) {
	    int v;
	    do {
	    	v = stack.top();
	    	stack.pop();
	    	in_stack[v] = false;
			component[v] = component_number;
	    } (u != v);
	    ++component_number;
    }
}
void tarjan() {
	for (int i = 0; i < graph.vertex_num; ++i) {
		DFS[i] = -1;
		low[i] = -1;
		in_stack[i] = false;
	}
	component_number = 0;
	index = 0;
	stack.clear();
	for (int v = 0; v < graph.vertex_num; ++v) {
		if (DFN[v] == -1) {
			tarjan_main(u);
		}
	}
}
