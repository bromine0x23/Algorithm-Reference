void query(Node * p, int l, int r) { // query (a, b]
	if (l<= p->l && p->r <= r) {
		// update p
		return;
	}

	push_down(p); // update p's children by p

	int mid = (p->l + p->r) / 2;
	if (l < m) { query(p->lc, l, r); }
	if (m < r) { query(p->rc, l, r); }
}
