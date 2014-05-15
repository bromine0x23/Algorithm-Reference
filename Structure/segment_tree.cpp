struct STNode {
	int l, r; // interval $\left[l, r\right]$
	STNode * lc;
	STNode * rc;
	STNode(int ll, int rr) : l(ll), r(rr), lc(NULL), rc(NULL) { }
	// other value
};
STNode * build(int l, int r) {
	STNode * p = new STNode(l, r);
	if (l < r) {
		int m = (l+r) / 2;
		p->lc = build(l  , m);
		p->rc = build(m+1, r);
	}
	return p;
}
void change(STNode * p, int l, int r) {
	if (l<= p->l && p->r <= r) {
		// update p and make lazy flag
		return;
	}

	push_down(p); // push p\'s lazy flag to p\'s children

	int m = (p->l + p->r) / 2;
	if (l < m) { change(p->lc, l, r); }
	if (m < r) { change(p->rc, l, r); }

	push_up(p); // update p by p\'s children
}
void query(STNode * p, int l, int r) { // query (a, b]
	if (l<= p->l && p->r <= r) {
		// update p
		return;
	}

	push_down(p); // update p's children by p

	int m = (p->l + p->r) / 2;
	if (l < m) { query(p->lc, l, r); }
	if (m < r) { query(p->rc, l, r); }
}
