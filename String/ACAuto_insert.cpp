void ACTrie::insert(char str[]) {
	ACTrieNode * p = root;

	for (int si=0; str[si] != '\0'; ++si) {
		int const idx = str[si];
		if (p->next[idx] == nullptr) {
			p->next[idx] = new ACTrieNode;
		}
		p = p->next[idx];
	}
	++(p->cnt);
}