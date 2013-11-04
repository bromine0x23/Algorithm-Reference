vector<int> C;
void Catalan(int n) {
	C = vector<int>(n+1);
	C[0] = 1;
	for (int i=1; i<=n; ++i) {
		C[i] =  (4*i-2) * C[i-1] / (i+1);
	}
}
