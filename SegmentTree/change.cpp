void change(Node * p, int l, int r) {
	if (l<= p->l && p->r <= r) {
		// update p and make lazy flag
		return;
	}

	push_down(p); // push p's lazy flag to p's children

	int m = (p->l + p->r) / 2;
	if (l < m) { change(p->lc, l, r); }
	if (m < r) { change(p->rc, l, r); }

	push_up(p); // update p by p's children
}
