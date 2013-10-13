struct Node {
	int l, r; // interval $\left[l, r\right]$
	Node * lc;
	Node * rc;
	Node(int ll, int rr) : l(ll), r(rr), lc(NULL), rc(NULL) { }
	// other value
};
