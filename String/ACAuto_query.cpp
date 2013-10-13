int query(char str[]) {
	ACTrieNode * const ROOT = trie->root;
	ACTrieNode * p = ROOT;
	int count = 0;
	for (int si=0; str[si] != '\0'; ++si) {
		int const idx = str[si];
		for (; p->next[idx]==nullptr && p!=ROOT; p=p->fail) { }
		p = (p->next[idx] != nullptr ? p->next[idx] : ROOT);
		for (ACTrieNode * tmp = p; tmp != ROOT && tmp->cnt != -1; ) {
			cnt += tmp->cnt;
			tmp->cnt = -1;
			tmp = tmp->fail;
		}
	}
	return count;
}
