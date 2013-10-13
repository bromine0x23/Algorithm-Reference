struct ACTrieNode {
	ACTrieNode * fail;
	ACTrieNode * next[CHAR_NUM];
	int cnt;
};

struct ACTrie {
	ACTrieNode * root;

	void insert(char[]);
};

struct ACAutomation {
	ACTrie * trie;

	ACAutomation(ACTrie *);

	int query(char[]);
};
