// time complexity of each operation is amortized $O(\log n)$
struct Treap {
	struct Node {
		int value, time; // element value \& multiplicity of elements
		int weight; // satisfy minimum heap property
		int sum;
		int size, count; // subtree node``s size, subtree``s element number
		union {
			Node * child[2]; // children, false -> left, true -> right
			struct {
				Node * left;
				Node * right;
			};
		};
	};
	Node * null;
	Node * root;
	Node * free;
	Node * get_node() {
		Node * node;
		if (free != NULL) {
			node = free;
			free = node->left;
		} else {
			node = new Node;
		}
		return node;
	}
	void put_node(Node * node) {
		if (free != NULL) {
			node->left = free;
		} else {
			node->left = NULL;
		}
		free = node;
	}
	Node * make_node(int value) {
		Node * node = get_node();
		node->value = value;
		node->time = 1;
		node->weight = rand();
		node->sum = value;
		node->size = node->count = 1;
		node->left = node->right = null;
		return node;
	}
	void init(){
		free = NULL;
		null = get_node();
		null->time = 0;
		null->weight = INF;
		null->sum = 0;
		null->size = null->count = 0;
		null->left = null->right = null;
		root = null;
	}
	void push_up(Node * node) {
		Node * lnode = node->left;
		Node * rnode = node->right;
		node->sum = lnode->sum + node->value + rnode->sum;
		node->size = lnode->size + 1 + rnode->size;
		node->count = lnode->count + node->time + rnode->count;
	}
	void push_down(Node * node) {
		// I don``t know what should it do.
	}
	void rotate(Node * & x, bool side) {
		Node * y = x->child[!side];
		push_down(y);
		push_down(x);
		x->child[!side] = y->child[side];
		y->child[side] = x;
		push_up(x);
		push_up(y);
		x = y;
	}
	// insert element
	void insert(int value) {
		insert(root, value);
	}
	void insert(Node * & node, int value) {
		if (node != null) {
			if (node->value == value) {
				++node->time;
				push_up(node);
			} else {
				bool side = node->value < value;
				insert(node->child[side], value);
				if (node->child[side]->weight < node->weight) {
					rotate(node, !side);
				}
				push_up(node);
			}
		} else {
			node = make_node(value);
		}
	}
	// erase element
	void erase(int value) {
		erase(root, value);
	}
	void erase(Node * & node, int value) {
		if (node->value == value) {
			if (node->time > 1) {
				--node->time;
				push_up(node);
			} else if (node->left != null || node->right != null) {
				rotate(node, node->left->weight < node->right->weight);
				erase(node, value);
				push_up(node);
			} else {
				put_node(node);
				node = null;
			}
		} else {
			erase(node->child[node->value < value], value);
			push_up(node);
		}
	}
	// find element in tree
	Node * find(int value) {
		return find(root, value);
	}
	Node * find(Node * node, int value) {
		for (; node != null; ) {
			if (node->value == value) {
				break;
			} else {
				node = node->child[node->value < value];
			}
		}
		return node;
	}
	// select node has $k$-small element in tree
	Node * select(int value) {
		return select(root, value);
	}
	Node * select(Node * node, int k) {
		for (; k > 0 && node != null;) {
			if (k <= node->left->count) {
				node = node->left;
			} else if (k <= node->left->count + node->time) {
				k = 0;
			} else {
				k -= node->left->count + node->time;
				node = node->right;
			}
		}
		return node;
	}
	// return value``s position in inorder result
	int rank(int value) {
		return rank(root, value);
	}
	int rank(Node * node, int value) {
		int r = 0;
		for (; node != null;) {
			if (value == node->value) {
				r += node->left->size;
				break;
			} else if (value < node->value) {
				node = node->left;
			} else {
				r += node->left->size + 1;
				node = node->right;
			}
		}
		return r;
	}
};
