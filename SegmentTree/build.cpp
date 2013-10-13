Node * build(int l, int r) {
	Node * p = new Node(l, r);
	if (l < r) {
		int m = (l+r) / 2;
		p->lc = build(l  , m);
		p->rc = build(m+1, r);
	}
	return p;
}
