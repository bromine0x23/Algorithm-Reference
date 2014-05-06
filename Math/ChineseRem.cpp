// sovle congruence equations
// $x \equiv a_1 \mod m_1$
// $x \equiv a_2 \mod m_2$
// $\vdots$
// $x \equiv a_n \mod m_n$
int chinese_remainder(int const a[], int const mod[], int const n) {
	// $r = \prod m_i$
	int r = accumlate(m, m + n, 1, multiplies<int>());
	// $p_i = r / m_i$
	vector<int> p(n);
	for (int i = 0; i < n; ++i) {
		p[i] = r / m[i];
	}
	// $y_i = p_i^{-1} \mod m_i$
	vector<int> y(n);
	for (int i = 0; i < n; ++i) {
		y[i] = (Euclid_extended(p[i], m[i]).x + m[i]) % m[i];
	}
	// $x \equiv \prod a_ip_iy_i \mod r$
	int x = 0;
	for (int i = 0; i < n; ++i) {
		x = (x + a[i] * p[i] * y[i]) % r;
	}
	return x;
}

