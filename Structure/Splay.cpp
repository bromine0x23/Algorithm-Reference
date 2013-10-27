struct SplayNode {
	int p
	union {
		int c[2];
		struct { int l, r; };
	};
	int v;
	int size; // amount of children
	int sum; // amount of children
};
struct Splay {
	SplayNode nodes[MAX_NODE_NUM];
	int node_count;
	int root;

	void init() {
		root = 0;
		nodes[root].r = nodes[root].l = nodes[root].p = root;
		nodes[root].sum = nodes[root].size = node_count = 0;
	}

	void new_node(int & x, int v) {

	}

	void splay(int x, int goal) {
		push_down(x);
		for (; nodes[x].p != goal;) {
			if (nodes[nodes[x].p].p != goal) {
				rotate(x, nodes[nodes[x].p].l == x);
			} else {
				int y = nodes[x].p;
				int z = nodes[y].p;
				bool f = (nodes[z].l == y);
				if (nodes[y].c[f] == x) {
					rotate(x, !f);
				} else {
					rotate(y, f);
				}
				rotate(x, f);
			}
		}
		push_up(x);
		if (goal == 0) {
			root = x;
		}
	}

	void rotate(int x, bool f) {
		int y = nodes[x].p;
		int z = nodes[y].p;
		push_down(y);
		push_down(x);
		nodes[y].c[!f] = nodes[x].c[f];
		nodes[nodes[x].c[f]].p = y;
		nodes[x].c[f] = y;
		nodes[y].p = x;
		nodes[x].p = z;
		if (nodes[x].p != 0) {
			nodes[x].c[nodes[z].r == y] = x;
		}
		push_up(y);
	}

	void rotate_to(int k, int goal) {
		int x = root;
		push_down(x);
		for (; nodes[nodes[x].l].s != k; ) {
			if (k < nodes[nodes[x].l].s) {
				x = nodes[x].l;
			} else {
				k -= nodes[nodes[x].l].s + 1;
				x = nodes[x].r;
			}
			push_down(x);
		}
		splay(x, goal);
	}
};
