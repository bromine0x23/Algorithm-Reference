struct Bignum {
	static int const MAX_BIGNUM_LEN;
	static int const BASE;
	bool sign; // positive => T, negative => F
	int len;
	int ds[MAX_BIGNUM_LEN];
	Bignum() : sign(true), len(0) {
		memset(ds, 0, sizeof(ds));
	}
	Bignum(Bignum const & src) : sign(src.sign), len(src.len) {
		memcpy(ds, src.ds, sizeof(ds[0])*len);
		memset(ds+len, 0, sizeof(ds[0])*(MAX_BIGNUM_LEN-len));
	}
	clear(bool s = true) {
		sign = s;
		len = 0;
		memset(ds, 0, sizeof(ds));
	}
};
// unsigned compare, $x<=>y$
int cmpu(Bignum const & x, Bignum const & y) {
	if (x.len < y.len) { return -1; }
	if (x.len > y.len) { return  1; }
	int const * x_d = x.ds + (x.len-1);
	int const * y_d = y.ds + (y.len-1);
	for (int n=0; n < x.len; ++n, --x_d, --y_d) {
		if (*x_d < *y_d) { return -1; }
		if (*x_d > *y_d) { return  1; }
	}
	return 0;
}
// signed compare, $x<=>y$
int cmp(Bignum const & x, Bignum const & y) const {
	return (x.sign == y.sign)
		? (x.sign ? cmpu(x, y) : cmpu(y, x))
		: (x.sign ? 1 : -1);
}
// unsigned add, $z=x+y$
void addu(Bignum & z, Bignum const & x, Bignum const & y) {
	z.len = max_by_ref(x.len, y.len);
	for (int i=0; i<z.len; ++i) {
		z.ds[i] += x.ds[i] + y.ds[i];
		z.ds[i+1] += z.ds[i] / BASE;
		z.ds[i] %= BASE;
	}
	for (; z.ds[z.len] > 0; ++z.len) { }
}
// unsigned sub, $z=x-y$
void subu(Bignum & z, Bignum const & x, Bignum const & y) {
	for (int i=0; i<x.len; ++i) {
		z.ds[i] += x.ds[i] - y.ds[i];
		if (z.ds[i] < 0) {
			--z.ds[i+1];
			z.ds[i] += BASE;
		}
	}
	for (z.len = x.len; z.len>0 && z.ds[z.len-1]==0; --z.len) { }
}
// signed add, $z=x+y$
void add(Bignum & z, Bignum const & x, Bignum const & y) {
	if (x.sign == y.sign) {
			     z.clear(x.sign); addu(z, x, y);
	} else {
		int cmp_res = cmpu(x, y);
		switch (cmp_res) {
		case -1: z.clear(y.sign); subu(z, y, x); break;
		case  0: z.clear(      );                break;
		case  1: z.clear(x.sign); subu(z, x, y); break;
		}
	}
}
// signed sub, $z=x-y$
void sub(Bignum & z, Bignum const & x, Bignum const & y) {
	if (x.sign != y.sign) {
		         z.clear(x.sign); addu(z,  x, y);
	} else {
		int cmp_res = cmpu(x, y);
		switch (cmp_res) {
		case -1: z.clear(y.sign); subu(z, !y, x); break;
		case  0: z.clear(      );                 break;
		case  1: z.clear(x.sign); subu(z,  x, y); break;
		}
	}
}
// bignum mul bignum, $z=x\cdot y$
void mul(Bignum & z, Bignum const & x, Bignum const & y) {
	z.sign = (x.sign == y.sign);
	for (int xi = 0; xi < x.len; ++xi) {
		int tmp = 0;
		for (int yi = 0; yi < y.len; ++yi) {
			tmp += x.ds[xi] * y.ds[yi] + z.ds[xi+yi];
			z.ds[xi+yi] = tmp % BASE;
			tmp /= BASE;
		}
		z.ds[xi+y.len] = tmp;
	}
	for(z.len = x.len + y.len; z.len>0 && z.ds[z.len-1]==0; --z.len) { }
}
// bignum mul digit, $z=x\cdot y$
void muld(Bignum & z, Bignum const & x, int y) {
	z.sign = (x.sign == (y>=0));
	y = abs(y);
	for (int i = 0; i < x.len; ++i) {
		z.ds[i] *= b;
		z.ds[i+1] += z.ds[i] / BASE;
		z.ds[i] %= BASE;
	}
	z.len = x.len + (z.ds[x.len] != 0);
}
// bignum div digit, $z=x/y$
int divd(Bignum & z, Bignum const & x, int y) {
	int rem, tmp = 0;
	for (int i=x.len-1; i > =0; --i) {
		tmp = tmp * BASE + x.ds[xi];
		if (tmp >= BASE) {
			rem = tmp / y;
			tmp -= rem * y;
		} else {
			rem = 0;
		}
		z.ds[i] = rem;
	}
	for (z.len = x.len; z.len>0 && z.ds[z.len-1]==0; --z.len) { }
	return rem;
}
