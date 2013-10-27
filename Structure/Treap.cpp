struct Treap {
	int key, weight, count, size;
	union {
		int child[2];
		struct {
			int left, right;
		};
	};
};
Treap treap[MAX_NODE_NUM];
int node_count;
int root;
void init(){
	root = 0;
	node_count = 0;
	treap[root].size = node_count;
	treap[root].weight = -INF;
}
void update(int x) {
	treap[x].size = treap[treap[x].left].size + treap[x].count + treap[treap[x].right].size;
}
void rotate(int & x, int f) {
    int y = treap[x].child[f];
    treap[x].child[f] = treap[y].child[1-f];
    treap[y].child[1-f] = x;
    update(x);
    update(y);
    x = y;
}
void insert(int & x, int f) {
	if (!x) {
		x = ++node_count;
		treap[x].key = f;
		treap[x].weight = rand();
		treap[x].count = 1;
		treap[x].right = treap[x].left = 0;
	} else if (treap[x].key == f) {
		++treap[x].count;
	} else {
		int k = (treap[x].key < f);
		insert(treap[x].child[k], f);
		if (treap[x].weight < treap[treap[x].child[k]].weight) {
			rotate(x, k);
		}
	}
	update(x);
}
void erase(int & x, int f) {
	if (treap[x].key == f) {
		if (treap[x].count == 1) {
			if (!treap[x].left && !treap[x].right) {
				x = 0;
				return;
			}
			rotate(x, treap[treap[x].left].weight<treap[treap[x].right].weight);
			erase(x, f);
		} else {
			--treap[x].count;
		}
	} else {
		erase(treap[x].child[treap[x].key<f], f);
	}
	update(x);
}
int select(int x,int k) {
	if (k<=0) {
		return -1;
	}
	if (k<=treap[treap[x].left].size) {
		return select(treap[x].left, k);
	}
	return k<=treap[treap[x].left].size+treap[x].count
		? treap[x].key
		: select(treap[x].right, k-treap[treap[x].left].size-treap[x].count);
}
