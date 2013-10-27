// sovle congruence equations
// $x\equiv a_1 \mod m_1$
// $x\equiv a_2 \mod m_2$
// $\vdots$
// $x\equiv a_n \mod m_n$
int ChineseRem(vector<int> a, vector<int> m, int n) {
	// $R = \prod m_i$
	int R = accumlate(m.begin(), m.end(), 1, multiplies<int>());
	// $M_i = R/m_i$
	vector<int> M(n);
	for (int i=0; i<n; ++i) {
		M[i] = R / m[i];
	}
	// $y_i = M_i^{-1} \mod m_i$
	vector<int> y(n);
	for (int i=0; i<n; ++i) {
		y[i] = (Euclid_extended(M[i], m[i]).x + m[i]) % m[i];
	}
	// $x = \prod a_iM_iy_i$
	int x = 0;
	for (int i=0; i<n; ++i) {
		x = (x + a[i] * M[i] * y[i]) % R;
	}
	return x;
}
