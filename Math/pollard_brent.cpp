// $O(\sqrt[4]{n})$
int factors[MAX_N];
int factor_num = 0;
void pollard_brent(int n) {
	if (miller_rabin(n)) {
        factors[factor_num++] = n;
    } else {
    	int d = 1;
    	int x = 1 + rand() % (n - 1);
    	int y = x;
    	int a = 120;
    	for (int i = 1, k = 0; ; ++k) {
			x = (x * x + a) % n;
			d = Euclid((y - x + n) % n, n);
			if (1 < d && d < n) {
				break;
			}
			if (x == y) {
				--a;
			}
			if (i == k) {
				y = x;
				i *= 2;
			}
		}
    	pollard_brent(d);
    	pollard_brent(n / d);
    }
}
