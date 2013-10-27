// dynamic tree: reference a forest with weight
struct DynamicTreeNode {
	DynamicTreeNode * parent;
	union {
		DynamicTreeNode * child[2];
		struct {
			DynamicTreeNode * left;
			DynamicTreeNode * right;
		};
	};
	bool is_reverse;
};
DynamicTreeNode nodes[MAX_NODE_NUM];
DynamicTreeNode * current;
DynamicTreeNode * nil;
DynamicTreeNode * new_node() {
	current->left = current->right = current->parent = nil;
	current->is_reverse = false;
	return current++;
}
void init(){
	current = nodes;
	nil = new_node();
}
struct DynamicTree {
	bool is_root(DynamicTreeNode * x) {
		return x->parent == nil || (x->parent->left != x && x->parent->right != x);
	}
	void push_up(DynamicTreeNode * x) { }
	void push_down(DynamicTreeNode * x) {
		if (x!=nil) {
			if (x->is_reverse) {
				x->is_reverse = 0;
				if (x->left != nil) {
					x->left->is_reverse ^= 1;
				}
				if (x->right != nil) {
					x->right->is_reverse ^= 1;
				}
				swap(x->left, x->right);
			}
		}
	}
	void rotate(DynamicTreeNode * x, int f) {
		if (!is_root(x)) {
			DynamicTreeNode * y = x->parent;
			y->child[1-f] = x->child[f];
			x->parent = y->parent;
			if (x->child[f] != nil) {
				x->child[f]->parent = y;
			}
			if (y != nil) {
				if (y == y->parent->left) {
					y->parent->left = x;
				} else if(y == y->parent->right) {
					y->parent->right = x;
				}
			}
			x->child[f] = y;
			y->parent = x;
			pushup(y);
		}
	}
	void splay(DynamicTreeNode * x) {
		stack<DynamicTreeNode *> S;
		S.push(x);
		for (DynamicTreeNode * y = x; !is_root(y); y = y->parent) {
			S.push(y->parent);
		}
		for (; !S.empty(); S.pop()) {
			push_down(S.top());
		}
		for (; !is_root(x); ) {
			DynamicTreeNode * y = x->parent;
			if (!is_root(y)) {
				rotate(x, x==y->left);
			} else {
				int f = (y->parent->left == y);
				if (y->child[f] == x) {
					rotate(x, 1^f);
				} else {
					rotate(y, f);
				}
				rotate(x, f);
			}
		}
		push_up(x);
	}
	DynamicTreeNode * access(DynamicTreeNode * u) {
		DynamicTreeNode * v = nil;
		while (u != nil){
			splay(u);
			v->parent = u;
			u->right = v;
			push_up(u);
			v = u;
			u = u->parent;
		}
		return v;
	}
	DynamicTreeNode * link(DynamicTreeNode *u, DynamicTreeNode *v) {
		access(u);
		splay(u);
		u->is_reverse = true;
		u->parent = v;
	}
	DynamicTreeNode * cut(DynamicTreeNode *u) {
		access(u);
		splay(u);
		u->left = u->left->parent = nil;
		push_up(u);
	}
	void change_root(DynamicTreeNode * u){
		access(u)->is_reverse ^= 1;
	}
	DynamicTreeNode * get_root(DynamicTreeNode *u) {
		access(u);
		for (splay(u); u->parent != nil) {
			u = u->parent;
		}
		splay(u);
		return u;
	}
	DynamicTreeNode * LCA(DynamicTreeNode * u, DynamicTreeNode * v){
		access(u);
		return access(v);
	}
	bool query(DynamicTreeNode * u, DynamicTreeNode * v) {
		while (u->parent != nil) {
			u = u->parent;
		}
		while (v->parent != nil) {
			v = v->parent;
		}
		return u==v;
	}

};
