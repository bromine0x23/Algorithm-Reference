// $O(m+n)$
struct ACAuto {
	int next[MAX_NODE_NUM][CHAR_NUM], fail[MAX_NODE_NUM], count[MAX_NODE_NUM];
	int node_count;
	int root;
	void init(){
		node_count = 0;
		root = new_node();
	}
	int new_node(){
		for(int i=0; i<CHAR_NUM; ++i) {
			next[node_count][i] = -1;
		}
		count[node_count] = 0;
		return node_count++;
	}
	void insert(char str[], int m = 1) {
		int u = root;
		for (int si=0; str[si]!='\0'; ++si) {
			if (next[u][str[i]] == -1) {
				next[u][str[i]] = new_node();
			}
			u = next[u][str[i]];
		}
		count[u] += m;
	}
	void build() {
		queue<int> Q;
		for(int i=0; i<CHAR_NUM; ++i) {
			if (next[root][i] == -1) {
				next[root][i] = root;
			} else {
				fail[next[root][i]] = root;
				Q.push(next[root][i]);
			}
		}
		for (; !Q.empty(); ) {
			int u = Q.front(); Q.pop();
			for(int i=0; i<CHAR_NUM; ++i) {
				if (next[u][i] == -1) {
					next[u][i] = next[fail[u]][i];
				} else{
					fail[next[u][i]] = next[fail[u]][i];
					Q.push(next[u][i]);
				}
			}
		}
	}
	int query(char str[]) {
		int u = root;
		int ans = 0;
		for (int si=0; str[si]!='\0'; ++si) {
			u = next[u][str[si]];
			for (int v=u; v!=root; v=fail[v]){
				ans += count[v]; count[v]=0;
			}
		}
		return ans;
	}
}
