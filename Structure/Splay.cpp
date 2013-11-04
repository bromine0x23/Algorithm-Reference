// maintain a sequance $s_1, s_2, \cdots, s_n$
// time complexity of each operation is amortized $O(\log n)$
struct SplayNode {
	SplayNode * p;
	union {
		SplayNode * c[2];
		struct { SplayNode *l, *r; };
	};
	int size; // amount of children
	int val, sum;
	int ls, rs, ss;
	bool lazy_rev;
	int lazy_same;
};
struct Splay {
	SplayNode *root, *nil, nodes[MAX_NODE], *pool[MAX_NODE];
	int node_count, alloc_node, pool_top;
	void rotate(int x, bool r) {
		SplayNode * y = x->p, * z = y->p;
		push_down(y); push_down(x);
		y->c[!r] = x->c[r];
		x->c[r]->p = y;
		x->c[r] = y;
		y->p = x;
		x->p = z;
		if (x->p != nil) {
			z->c[z->r == y] = x;
		}
		push_up(y);
	}
	// rotate x under the goal
	void splay(SplayNode * x, SplayNode * goal) {
		push_down(x);
		for (; x->p != goal; ) {
			if (x->p->p == goal) {
				rotate(x, x->p->l == x);
			} else {
				SplayNode * y = x->p;
				bool r = (y->p->l == y);
				if (y->c[r] == x) {
					rotate(x, !r);
				} else {
					rotate(y, r);
				}
				rotate(x, r);
			}
		}
		push_up(x);
		if (goal == nil) { root = x; }
	}
	// rotate k-th greatest node under the goal
	void rotate_to(int k, SplayNode * goal) {
		SplayNode * x = root;
		push_down(x);
		for (; x->l->size != k;) {
			if (k < x->l->size) {
				x = x->l;
			} else {
				k -= x->l->size + 1;
				x = x->r;
			}
			push_down(x);
		}
		splay(x, goal);
	}
	void push_up(SplayNode * x) {
		SplayNode *lx = x->l, *lr = x->r;
		x->size = lx->size + 1 + rx->size;
		x->sum = lx->sum + x->val + rx->sum;
		x->ls = max(lx->ls, lx->sum + x->val + max(0, rx->ls));
		x->rs = max(rx->rs, rx->sum + x->val + max(0, lx->rs));
		x->ss = max(max(lx->ss, rx->ss), max(0, lx->rs) + x->val + max(0, rx->ls));
	}
	void push_down(SplayNode * x) {
		if (x->lazy_rev) {
			update_rev(x->l);
			update_rev(x->r);
			x->lazy_rev = false;
		}
		if (x->lazy_same != -INF) {
			update_same(x->l, x->lazy_same);
			update_same(x->r, x->lazy_same);
			x->lazy_same = -INF;
		}
	}
	void update_rev(SplayNode * x) {
		if (x != nil) {
			swap(x->l, x->r);
			swap(x->ls, x->rs);
		}
		x->lazy_rev ^= true;
	}
	void update_same(SplayNode * x, int v) {
		if (x != nil) {
			x->val = v;
			x->sum = v * x->size;
			x->ss = x->rs = x->ls = max(v, v*x->size);
			x->lazy_same = v;
		}
	}
	SplayNode * new_node(int v) {
		SplayNode * x = (pool_top != 0 ? pool[pool_top--] : &nodes[alloc_node++]);
		x->r = x->l = x->p = nil;
		x->size = 1;
		x->ss = x->rs = x->ls = x->sum = x->val = v;
		x->lazy_rev = false; x->lazy_same = -INF;
		return x;
	}
	void clear() {
		pool_top = alloc_node = node_count = 0;
		nil = new_node(-INF); nil->size = 0; nil->sum = 0;
		root = new_node(-INF);
		root->r = new_node(-INF);
		root->r->p = root;
		root->size = 2;
	}
	void init(int data[], int n) {
		clear();
		node_count = n;
		rotate_to(0, nil); rotate_to(1, root);
		root->r->l = build(1, n, root->r, data);
		push_up(root->r); push_up(root);
	}
	SplayNode * build(int l, int r, SplayNode * p, int data[]) {
		if (l>r) { return nil; }
		push_down(p);
		int m = (l+r)/2;
		SplayNode * x = new_node(data[m]);
		x->p = p; x->l = build(l, m-1, x, data); x->r = build(m+1, r, x, data);
		push_up(x);
		return x;
	}
	// insert $c_1, c_2, \cdots, c_n$ after pos
	void insert(int pos, int data[], int n) {
		node_count += n;
		rotate_to(pos, nil);
		rotate_to(pos+1, root);
		root->r = root->l = build(1, n, root->r, data);
		push_up(root->r); push_up(root);
	}
	void erase(SplayNode * x) {
		if (x != nil) {
			pool[++pool_top] = x;
			erase(x->l); erase(x->r);
		}
	}
	// delete $s_l, \cdots, s_r$
	void erase(int l, int r) {
		rotate_to(l-1, null); rotate_to(r+1, root);
		SplayNode * key = root->r->l;
		root->r->l = nil;
		node_count -= key->size;
		erase(key);
		push_up(root->r); push_up(root);
	}
	// change numbers from l to r to v
	void change(int l, int r, int v) {
		rotate_to(l-1, null); rotate_to(r+1, root);
		SplayNode * key = root->r->l;
		update_same(key, v);
		push_up(root->r); push_up(root);
	}
	// reverse $s_l, \cdots, s_r$ to $s_r, \cdots, s_l$
	void reverse(int l, int r) {
		rotate_to(l-1, null); rotate_to(r+1, root);
		SplayNode * key = root->r->l;
		update_rev(key, v);
	}
	// calculate $s_l+\cdots+s_r$
	void sum(int l, int r) {
		rotate_to(l-1, null); rotate_to(r+1, root);
		SplayNode * key = root->r->l;
		return key->sum;
	}
	// calculate max sub sequance sum
	void max_subsum() {
		rotate_to(0, null); rotate_to(node_count, root);
		SplayNode * key = root->r->l;
		return key->ss;
	}
};
