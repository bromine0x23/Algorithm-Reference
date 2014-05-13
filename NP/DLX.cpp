struct DLXNode {
	int L, R, U, D;
	int row, col; // row or colunm head
};
DLXNode nodes[MAX_NODE_NUM]; // $N_0, N_1, \cdots$
int node_num;
int row_num; // $R$
int col_num; // $C$
int size[col_num]; // $S_i$ amount of 1 for each column
void init(int C) {
	// $N_0$ is column's head's head
	// $N_1 \cdots N_C$ is column's head
	row_num = 0;
	col_num = C;
	for (int col = 0; col <= col_num; ++col) {
		nodes[col].L = col - 1;
		nodes[col].R = col + 1;
		nodes[col].D = nodes[col].U = col;
		nodes[col].col = col;
		nodes[col].row = 0;
		size[col] = 0;
	}
	nodes[0].L = col_num;
	nodes[col_num].R = 0;
	node_num = col_num;
}
int new_node() {
	return ++node_num;
}
void add_line(bool row[]) {
	for (int col = 1; col <= col_num; ++col) {
		if (row[col - 1]) {
			int x = new_node();
			if (col == 1) {
				nodes[x].R = nodes[x].L = x;
			} else {
				nodes[x].L = x - 1;
				nodes[x].R = nodes[x - 1].R;
				nodes[nodes[x - 1].R].L = x;
				nodes[x - 1].R = x;
			}
			nodes[x].D = col;
			nodes[x].U = nodes[col].U;
			nodes[nodes[col].U].D = x;
			nodes[col].U = x;
			++size[col];
			nodes[x].row = row_num;
			nodes[x].col = col;
		}
	}
}
// index range is $\{1, 2, \cdots, C\}$
void add_line_by_index(int col_index[], int index_num) {
	for (int col = 0; col < index_num; ++col) {
		int x = new_node();
		if (col == 0) {
			nodes[x].R = nodes[x].L = x;
		} else {
			nodes[x].L = x - 1;
			nodes[x].R = nodes[x - 1].R;
			nodes[nodes[x - 1].R].L = x;
			nodes[x - 1].R = x;
		}
		nodes[x].D = col_index[ri];
		nodes[x].U = nodes[col_index[ri]].U;
		nodes[nodes[col_index[ri]].U].D = x;
		nodes[col_index[ri]].U = x;
		++size[col_index[ri]];
		nodes[x].row = row_num;
		nodes[x].col = col_index[ri];
	}
}
void removeLR(int x) {
	nodes[nodes[x].R].L = nodes[x].L;
	nodes[nodes[x].L].R = nodes[x].R;
}
void removeUD(int x) {
	nodes[nodes[x].D].U = nodes[x].U;
	nodes[nodes[x].U].D = nodes[x].D;
}
void remove(int x) {
	removeLR(x);
	for (int i = nodes[x].D; i != x; i = nodes[i].D) {
		for (int j = nodes[i].R; j != i; j = nodes[j].R) {
			removeUD(j);
			--size[nodes[j].col];
		}
	}
}
void resumeLR(int x) {
	nodes[nodes[x].L].R = nodes[nodes[x].R].L = x;
}
void resumeUD(int x) {
	nodes[nodes[x].U].D = nodes[nodes[x].D].U = x;
}
void resume(int x) {
	for (int i = nodes[x].U; i != x; i = nodes[i].U) {
		for (int j = nodes[i].L; j != i; j = nodes[j].L) {
			removeUD(j);
			++size[nodes[j].col];
		}
	}
	resumeLR(x);
}
bool DLX(deque<int> & ans, int k) {
	int c = nodes[0].R;
	if (c == 0) { return true; }
	remove(c);
	for (int i = nodes[c].D; i != c; i = nodes[i].D) {
		ans.push_back(nodes[i].row);
		for (int j = nodes[i].R; j != i; j = nodes[j].R) {
			remove(nodes[j].col);
		}
		if (DLX(ans, k + 1)) {
			return true;
		}
		for (int j = nodes[i].L; j != i; j = nodes[j].L) {
			resume(nodes[j].col);
		}
		ans.pop_back();
	}
	resume(c);
	return false;
}
