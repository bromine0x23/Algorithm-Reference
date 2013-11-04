// time complexity of each operation is amortized $O(\log n)$
struct Treap {
	int k; // key
	int w; // weight
	int c; // node multiplicity
	int s; // sub tree size
	union {
		int c[2];
		struct { int l, r; };
	};
};
Treap treap[MAX_NODE_NUM];
int node_count;
int root;
void init(){
	root = 0;
	node_count = 0;
	treap[root].r = treap[root].l = 0;
	treap[root].s = 0;
	treap[root].w = -INF;
}
void update(int x) {
	treap[x].s = treap[treap[x].l].s + treap[x].c + treap[treap[x].r].s;
}
void rotate(int & x, bool r) {
    int y = treap[x].c[!r];
    treap[x].c[!r] = treap[y].c[r];
    treap[y].c[r] = x;
    update(x);  update(y);
    x = y;
}
void insert(int & x, int v) {
	if (!x) {
		x = ++node_count;
		treap[x].k = v;
		treap[x].w = rand();
		treap[x].c = 1;
		treap[x].r = treap[x].l = 0;
	} else if (treap[x].k == v) {
		++treap[x].c;
	} else {
		bool r = (f < treap[x].k);
		insert(treap[x].c[r], v);
		if (treap[x].w < treap[treap[x].c[r]].w) {
			rotate(x, r);
		}
	}
	update(x);
}
void erase(int & x, int v) {
	if (treap[x].key == v) {
		if (treap[x].c == 1) {
			if (treap[x].l==0 && treap[x].r==0) {
				x = 0;
				return;
			}
			rotate(x, treap[treap[x].r].w < treap[treap[x].l].w);
			erase(x, v);
		} else {
			--treap[x].c;
		}
	} else {
		erase(treap[x].c[f<treap[x].k], f);
	}
	update(x);
}
int select(int x, int k) {
	if (k<=0) {
		return -1;
	}
	if (k<=treap[treap[x].l].s) {
		return select(treap[x].l, k);
	}
	return k<=treap[treap[x].l].s+treap[x].c
		? treap[x].key
		: select(treap[x].r, k-treap[treap[x].l].s-treap[x].c);
}
