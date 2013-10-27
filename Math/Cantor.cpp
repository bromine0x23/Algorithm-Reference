//  $FACTORIAL_n = n!$
int const FACTORIAL[];
int encantor(int seq[], int n) {
	int num=0;
	for (int i=0; i<n-1; ++i) {
		int t = 0;
		for (int j=i+1; j<n; ++j) {
			t += (seq[j] < seq[i]);
		}
		num += FACTORIAL[n-1-i] * t;
	}
	return num;
}
void decantor(int seq[], int cantor, int n) {
	vector<bool> appeared(n, false);
	for (int i=0; i<n; i++) {
		int t = cantor / FACTORIAL[n-1-i] + 1;
		cantor %= FACTORIAL[n-1-i];
		int j=1;
		for (int r=0; ; ++j) {
			r += !appeared[j];
			if(r==t){
				break;
			}
		}
		seq[i]=j;
		appeared[j] = true;
	}
}
