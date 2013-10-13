struct BiGraph {
	int x_num, y_num;
	vector< vector<bool> > edge;
	BIPARTITE_GRAPH(int xn, int yn) :
		x_num(xn), y_num(yn),
		edge(x_num, vector<bool>(y_num, false)) { }
};
