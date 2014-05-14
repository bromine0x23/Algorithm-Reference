// time complexity of each operation is $O(\log n)$, expect maintain which is $O(1)$
struct SBTNode {
	int key;
	int size;
	union {
		int c[2]; // children, false -> l, true -> r
		struct { int l, r; }; // left and right child
	};
	void new_node(int value) {
		key = value;
		size = 1;
		l = r = 0;
	}
}
SBTNode SBT[MAX_NODE];
int count;
int root;
void init() {
	root = 0;
	count = 0;
}
void rotate(int & x, bool side) {
	int y = SBT[x].child[!side];
	SBT[x].c[!side] = SBT[y].c[side];
	SBT[y].c[side] = x;
	SBT[y].size = SBT[x].size;
	SBT[x].size = SBT[SBT[x].l].size + 1 + SBT[SBT[x].r].size;
	x = y;
}
void lrotate(int & node) {
	rotate(node, false);
}
void rrotate(int & node) {
	rotate(node, true);
}
int find(int node, int value) {
	if (node != 0 && SBT[node].key != value) {
		if (value < SBT[node].key) {
			return find(SBT[node].l, value);
		} else {
			return find(SBT[node].r, value);
		}
	} else {
		return node;
	}
}
void maintain(int & node, bool side) {
	if (SBT[SBT[SBT[node].c[side]].c[side]].size > SBT[SBT[node].c[!side]].size) {
		rotate(node, !side);
	} else if (SBT[SBT[SBT[node].c[side]].c[!side]].size > SBT[SBT[node].c[!side]].size) {
		rotate(SBT[node].c[side], side);
		rotate(node, !side);
	} else {
		return;
	}
	lmaintain(SBT[node].l);
	rmaintain(SBT[node].r);
	lmaintain(x);
	rmaintain(x);
}
void lmaintain(int & node) {
	maintain(int & node, false);
}
void rmaintain(int & node) {
	maintain(int & node, true);
}
void insert(int & node, int value) {
	if (!node) {
		node = ++count;
		SBT[node].new_node(value);
		return;
	}
	++SBT[node].size;
	if (value < SBT[node].key) {
		insert(SBT[node].l, value);
		lmaintain(node);
	} else {
		insert(SBT[node].r, value);
		rmaintain(node);
	}
}
int erase(int & node, int value) {
	--SBT[node].size;
	if (value == SBT[node].key || (value < SBT[node].key && !SBT[node].l) || (value > SBT[node].key && !SBT[node].r)) {
		if (SBT[node].l && SBT[node].r) {
			int p = erase(SBT[node].l, value + 1);
			SBT[node].key = SBT[p].key;
			return p;
		} else {
			int p = node;
			node = SBT[node].l + SBT[node].r;
			return p;
		}
	} else {
		return erase(value < SBT[node].key ? SBT[node].l : SBT[node].r, value);
	}
}
int pred(int node, int value) {
	if (!node) {
		return -1;
	} else if (value <= SBT[node].key) {
		return pred(SBT[node].l, value);
	} else {
		return maximum(SBT[node].key, pred(SBT[node].r, value));
	}
}
int succ(int node, int value) {
	if (!node) {
		return INF;
	} else if (value >= SBT[node].key) {
		return succ(SBT[node].r, value);
	} else {
		return minimum(SBT[node].key, succ(SBT[node].l, value));
	}
}
// return $k$-small element in the tree which root is $node$
int select(int node, int k) {
	if (k == SBT[SBT[node].l].size + 1) {
		return SBT[node].key;
	} else if (k <= SBT[SBT[node].l].size) {
		return select(SBT[node].l, k);
	} else {
		return select(SBT[node].r, k- 1 - SBT[SBT[node].l].size);
	}
}
// return $x$ that $x$ is $k$-small element in the tree which root is $node$
int rank(int node, int k) {
	if (!node) {
		return 1;
	} else if (k <= SBT[node].key) {
		return rank(SBT[node].l,k);
	} else {
		return SBT[SBT[node].l].size + 1 + rank(SBT[node].r, k);
	}
}
