// time complexity of each operation is $O(\log n)$, expect maintain which is $O(1)$
struct SBT {
	struct Node {
		int value, time;
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
	Node * get_node(); // \SourceRef{source:treap}
	void put_node(Node * node); // \SourceRef{source:treap}
	Node * make_node(int value) {
		Node * node = new_node();
		node->value = value;
		node->time = 1;
		node->sum = value;
		node->size = node->count = 1;
		node->left = node->right = null;
		return node;
	}
	void init(){
		free = NULL;
		null = get_node();
		null->time = 0;
		null->sum = 0;
		null->size = null->count = 0;
		null->left = null->right = null;
		root = null;
	}
	void push_up(Node * node); // \SourceRef{source:treap}
	void push_down(Node * node); // \SourceRef{source:treap}
	void rotate(Node * & x, bool side); // \SourceRef{source:treap}
	void maintain(Node * & node, bool side) {
		if (node->child[side]->child[side]->size  > node->child[!side]->size) {
			rotate(node, !side);
		} else if (node->child[side]->child[!side]->size > node->child[!side]->size) {
			rotate(node->child[side], side);
			rotate(node, !side);
		} else {
			return;
		}
		maintain(node->left, false);
		maintain(node->right, true);
		maintain(node, false);
		maintain(node, true);
	}
	// insert element
	void insert(int value); // \SourceRef{source:treap}
	void insert(Node * & node, int value) {
		if (node != null) {
			if (node->value == value) {
				++node->time;
				push_up(node);
			} else {
				bool side = node->value < value;
				insert(node->child[side], value);
				push_up(node);
				maintain(node, side);
			}
		} else {
			node = init_node(value);
		}
	}
	// erase element
	void erase(int value); // \SourceRef{source:treap}
	void erase(Node * & node, int value) {
		if (node->value == value) {
			if (node->time > 1) {
				--node->time;
				push_up(node);
			} else if (node->left == null && node->right == null) {
				put_node(node);
				node = null;
			} else if (node->right == null) {
				node = node->left;
				push_up(node);
			} else if (node->left == null) {
				node = node->right;
				push_up(node);
			} else {
				bool side = node->value < value;
				rotate(node, side);
				erase(node->child[side], value);
				push_up(node);
			}
		} else {
			erase(node->child[node->value < value], value);
			push_up(node);
		}
	}
	Node * find(int value); // \SourceRef{source:treap}
	Node * find(Node * node, int value); // \SourceRef{source:treap}
	Node * select(int k); // \SourceRef{source:treap}
	Node * select(Node * node, int k); // \SourceRef{source:treap}
	int rank(int value); // \SourceRef{source:treap}
	int rank(Node * node, int value); // \SourceRef{source:treap}
};
