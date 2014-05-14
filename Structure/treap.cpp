// time complexity of each operation is amortized $O(\log n)$
struct Treap {
	int key;
	int weight;
	int time; // number of elements that have same value
	int size; // sub tree size
	union {
		int c[2]; // children, false -> l, true -> r
		struct { int l, r; };
	};
};
Treap treap[MAX_NODE_NUM];
int node_count;
int root;
void init(){
	root = 0;
	node_count = 0;
	treap[root].weight = -INF;
	treap[root].time = 0;
	treap[root].size = 0;
	treap[root].r = treap[root].l = 0;
}
int get_node(int value) {
	int x = ++node_count;
	treap[x].key = value;
	treap[x].weight = rand();
	treap[x].time = 1;
	treap[x].size = 0;
	treap[x].r = treap[x].l = 0;
	return x;
}
void update(int node) {
	treap[node].size = treap[treap[node].l].size + treap[node].time + treap[treap[node].r].size;
}
void rotate(int & x, bool side) {
    int y = treap[x].c[!side];
    treap[x].c[!side] = treap[y].c[side];
    treap[y].c[side] = x;
    update(x);
    update(y);
    x = y;
}
void lrotate(int & node) {
	rotate(node, false);
}
void rrotate(int & node) {
	rotate(node, true);
}
void insert(int & node, int value) {
	if (node == 0) {
		node = get_node(value);
	} else if (treap[node].key == value) {
		++treap[node].time;
	} else {
		if (value < treap[node].key) {
			insert(treap[node].l, value);
			if (treap[node].weight < treap[treap[node].l].weight) {
				rrotate(node);
			}
		} else {
			insert(treap[node].r, value);
			if (treap[node].weight < treap[treap[node].r].weight) {
				lrotate(node);
			}
		}
	}
	update(node);
}
void erase(int & node, int value) {
	if (treap[node].key == value) {
		if (treap[node].time == 1) {
			if (treap[node].l == 0 && treap[node].r == 0) {
				node = 0;
				return;
			}
			rotate(node, treap[treap[x].r].weight < treap[treap[x].l].weight);
			erase(node, v);
		} else {
			--treap[node].time;
		}
	} else {
		if (value < treap[node].key) {
			erase(treap[node].l, v);
		} else {
			erase(treap[node].r, v);
		}
	}
	update(node);
}
// select kth element
int select(int node, int k) {
	if (k <= 0) {
		return -1;
	} else if (k <= treap[treap[node].l].size) {
		return select(treap[node].l, k);
	} else if (k <= treap[treap[node].l].size + treap[node].time) {
		return treap[node].key;
	} else {
		return select(treap[node].r, k - treap[treap[node].l].size - treap[node].time);
	}
}
