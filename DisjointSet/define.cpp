struct DisjointSet {
	// $O(m\alpha(n))$, $m$ is number of operations, $n$ is size of set
	vector<int> parent, rank;
	DisjointSet(int size);
	int  find(int x);
	void link(int x, int y);
};
