ACAutomation::ACAutomation(ACTrie * t) : trie(t) {
	ACTrieNode * const ROOT = trie->root;

	queue<ACTrieNode * > Q;

	ROOT->fail = NULL;
	Q.push(ROOT);

	while (!Q.empty()) {
		ACTrieNode * curr = Q.front();
		Q.pop();

		for (int ci=0; ci<CHAR_NUM; ++ci) {
			if (curr->next[ci]) {
				ACTrieNode * p = curr->fail;
				for (; p != NULL && p->next[ci] == NULL; p=p->fail) { }
				curr->next[ci]->fail = (p != NULL ? p->next[ci] : ROOT);
				Q.push(curr->next[ci]);
			}
		}
	}
}