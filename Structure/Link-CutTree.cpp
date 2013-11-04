// Link-Cut Tree: reference a forest with weight
// time complexity of each operation is amortized $O(\log n)$
struct LCTreeNode {
	LCTreeNode * p;
	union {
		LCTreeNode * c[2];
		struct { LCTreeNode *l, *r; };
	};
	bool rev;
};
struct LCTree {
	LCTreeNode *nil, *curr, nodes[MAX_NODE_NUM];
	void init() {
		curr = nodes;
		nil = new_node();
	}
	LCTreeNode * new_node() {
		curr->r = curr->l = curr->p = nil;
		curr->rev = false;
		return curr++;
	}
	bool is_root(LCTreeNode * u) {
		return u->p == nil || (u->p->l!=u && u->p->r!=u);
	}
	LCTreeNode * access(LCTreeNode * u) {
		LCTreeNode * v = nil;
		for (; u != nil; u = u->p) {
			splay(u);
			v->p = u; u->r = v;
			push_up(u);
			v = u;
		}
		return v;
	}
	void link(LCTreeNode * u, LCTreeNode * v) {
		access(u); splay(u);
		u->p = v; u->rev = true;
	}
	void cut(LCTreeNode * u) {
		access(u); splay(u);
		u->l = u->l->p = nil;
		push_up(u);
	}
	void splay(LCTreeNode * u) {
		stack<LCTreeNode *> S; S.push(u);
		for (LCTreeNode * v=u; !is_root(v); v=v->p) { S.push(v->p); }
		for (; !S.empty(); S.pop()) { push_down(S.top()); }
		for (; !is_root(u); ) {
			LCTreeNode * y = x->p;
			if (!is_root(y)) {
				rotate(x, x==y->l);
			} else {
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
	}
	void rotate(int x, bool r) {
		if (is_root(x)) { return; }
		SplayNode * y = x->p;
		y->c[!r] = x->c[r];
		if (x->c[r] != nil) { x->c[r]->p = y; }
		x->c[r] = y;
		y->p = x;
		x->p = y->p;
		if (y != nil) {
			if (x->p != nil) {
				z->c[z->r == y] = x;
			}
		}
		push_up(y);
	}
	void make_root(LCTreeNode * u) {
		access(u)->rev ^= true; splay(u);
	}
	LCTreeNode * get_root(LCTreeNode * u) {
		access(u); splay(u);
		for (; u->p != nil; u=u->p) { }
		splay(u);
		return u;
	}
	bool same_set(LCTreeNode * u, LCTreeNode * v) {
		for (; u->p != nil; u=u->p) { }
		for (; v->p != nil; v=v->p) { }
		return u != v;
	}
	LCTreeNode * LCA(LCTreeNode * u, LCTreeNode * v) {
		access(u); return access(v);
	}
};
