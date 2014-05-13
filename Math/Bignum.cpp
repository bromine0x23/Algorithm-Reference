struct Bignum {
	static int const MAX_LENGTH;
	static int const BASE; // maybe 1000 is fine
	bool sign; // positive => T, negative => F
	int length;
	int digits[MAX_LENGTH];
	Bignum() : sign(true), length(0) {
		memset(digits, 0, sizeof(digits));
	}
	Bignum(Bignum const & src) : sign(src.sign), length(src.length) {
		memcpy(digits, src.digits, sizeof(digits));
	}
	void clear(bool s = true) {
		sign = s;
		length = 0;
		memset(digits, 0, sizeof(digits));
	}

	void clamp() {
		for (; length > 0 && digits[length - 1] == 0; --length) { }
	}
};
// unsigned compare, $x<=>y$
int cmpu(Bignum const & x, Bignum const & y) {
	if (x.length < y.length) { return -1; }
	if (x.length > y.length) { return  1; }
	int const * x_d = x.digits + (x.length - 1);
	int const * y_d = y.digits + (y.length - 1);
	for (int n=0; n < x.length; ++n, --x_d, --y_d) {
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
	z.length = maximum(x.length, y.length);
	for (int i = 0; i < z.length; ++i) {
		z.digits[i] += x.digits[i] + y.digits[i];
		z.digits[i + 1] += z.digits[i] / BASE;
		z.digits[i] %= BASE;
	}
	for (; z.ds[z.length] > 0; ++z.length) { }
}
// unsigned sub, $z=x-y$
void subu(Bignum & z, Bignum const & x, Bignum const & y) {
	for (int i = 0; i < x.length; ++i) {
		z.digits[i] += x.digits[i] - y.digits[i];
		if (z.digits[i] < 0) {
			--z.digits[i + 1];
			z.digits[i] += BASE;
		}
	}
	z.length = x.length;
	z.clamp();
}
// signed add, $z=x+y$
void add(Bignum & z, Bignum const & x, Bignum const & y) {
	if (x.sign == y.sign) {
		z.clear(x.sign);
		addu(z, x, y);
	} else {
		switch (cmpu(x, y)) {
		case -1:
			z.clear(y.sign);
			subu(z, y, x);
			break;
		case  0:
			z.clear();
			break;
		case  1:
			z.clear(x.sign);
			subu(z, x, y);
			break;
		}
	}
}
// signed sub, $z=x-y$
void sub(Bignum & z, Bignum const & x, Bignum const & y) {
	if (x.sign != y.sign) {
		z.clear(x.sign);
		addu(z,  x, y);
	} else {
		switch (cmpu(x, y)) {
		case -1:
			z.clear(!y.sign);
			subu(z, y, x);
			break;
		case  0:
			z.clear();
			break;
		case  1:
			z.clear(x.sign);
			subu(z, x, y);
			break;
		}
	}
}
// bignum mul bignum, $z=x\cdot y$
void mul(Bignum & z, Bignum const & x, Bignum const & y) {
	z.sign = (x.sign == y.sign);
	for (int xi = 0; xi < x.length; ++xi) {
		int tmp = 0;
		for (int yi = 0; yi < y.length; ++yi) {
			tmp += x.digits[xi] * y.digits[yi] + z.digits[xi+yi];
			z.digits[xi + yi] = tmp % BASE;
			tmp /= BASE;
		}
		z.digits[xi + y.length] = tmp;
	}
	z.length = x.length + y.length;
	z.clamp();
}
// bignum mul digit, $z=x\cdot y$
void muld(Bignum & z, Bignum const & x, int y) {
	z.sign = (x.sign == (y>=0));
	y = abs(y);
	for (int i = 0; i < x.length; ++i) {
		z.digits[i] *= b;
		z.digits[i + 1] += z.digits[i] / BASE;
		z.digits[i] %= BASE;
	}
	if (z.digits[x.length] == 0) {
		z.length = x.length;
	} else {
		z.length = x.length + 1;
	}
}
// bignum div digit, $z=x/y$
int divd(Bignum & z, Bignum const & x, int y) {
	int rem, tmp = 0;
	for (int i=x.length - 1; i > =0; --i) {
		tmp = tmp * BASE + x.digits[xi];
		if (tmp >= BASE) {
			rem = tmp / y;
			tmp -= rem * y;
		} else {
			rem = 0;
		}
		z.digits[i] = rem;
	}
	z.length = x.length;
	z.clamp();
	return rem;
}
