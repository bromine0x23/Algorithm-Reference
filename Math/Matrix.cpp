template<class Tp, int SIZE>
struct Row {
	typedef Tp ValType;
	ValType r[SIZE];
	ValType & operator()(int j) { return r[j]; }
	ValType const & operator()(int j) const { return r[j]; }
	Row & operator=(Row const & y) {
		for (int j=0; j<SIZE; ++j) {
			(*this)(j) = y(j);
		}
		return *this;
	}
};
template<class Tp, int SIZE>
struct Col {
	typedef Tp ValType;
	ValType c[SIZE];
	ValType & operator()(int i) { return c[i]; }
	ValType const & operator()(int i) const { return c[i]; }
	Col & operator=(Col const & y) {
		for (int i=0; i<SIZE; ++i) {
			(*this)(i) = y(i);
		}
		return *this;
	}
};
template<class Tp, int SIZE>
struct SqrMatrix {
	typedef Tp ValType;
	ValType s[SIZE][SIZE];
	ValType & operator()(int i, int j) { return s[i][j]; }
	ValType operator()(int i, int j) const { return s[i][j]; }
	SqrMatrix & operator=(SqrMatrix const & y) {
		for (int i=0; i<SIZE; ++i) {
			for (int j=0; j<SIZE; ++j) {
				(*this)(i, j) = y(i, j);
			}
		}
		return *this;
	}
	SqrMatrix & operator+=(SqrMatrix const & y) {
		for (int i=0; i<SIZE; ++i) {
			for (int j=0; j<SIZE; ++j) {
				(*this)(i, j) += y(i, j);
			}
		}
		return *this;
	}
	SqrMatrix & operator*=(int y) {
		for (int i=0; i<SIZE; ++i) {
			for (int j=0; j<SIZE; ++j) {
				(*this)(i, j) *= y;
			}
		}
		return *this;
	}
	SqrMatrix operator-() const {
		SqrMatrix res;
		for (int i=0; i<SIZE; ++i) {
			for (int j=0; j<SIZE; ++j) {
				res(i, j) = -(*this)(i, j);
			}
		}
		return *this;
	}
	SqrMatrix operator~() const {
		SqrMatrix res;
		for (int i=0; i<SIZE; ++i) {
			for (int j=0; j<SIZE; ++j) {
				res(i, j) = (*this)(j, i);
			}
		}
		return *this;
	}
	static SqrMatrix identity() {
		SqrMatrix res;
		for (int i=0; i<SIZE; ++i) {
			for (int j=0; j<SIZE; ++j) {
				res(i, j) = (i == j);
			}
		}
		return res;
	}
};
template<class Tp, int SIZE>
SqrMatrix<Tp, SIZE> operator*(SqrMatrix<Tp, SIZE> const & x, SqrMatrix<Tp, SIZE> const & y) {
	SqrMatrix<Tp, SIZE> res;
	for (int i=0; i<SIZE; ++i) {
		for (int j=0; j<SIZE; ++j) {
			Tp t = 0;
			for (int k=0; k<SIZE; ++k) {
				t += x(i, k) * y(k, j);
			}
			res(i, j) = t;
		}
	}
}
template<class Tp, int SIZE>
Row<Tp, SIZE> operator*(Row<Tp, SIZE> const & x, SqrMatrix<Tp, SIZE> const & y) {
	Row<Tp, SIZE> res;
	for (int j=0; j<SIZE; ++j) {
		Tp t = 0;
		for (int k=0; k<SIZE; ++k) {
			t += x(k) * y(k, j);
		}
		res(j) = t;
	}
}
template<class Tp, int SIZE>
Col<Tp, SIZE> operator*(SqrMatrix<Tp, SIZE> const & x, Col<Tp, SIZE> const & y) {
	Col<Tp, SIZE> res;
	for (int i=0; i<SIZE; ++i) {
		Tp t = 0;
		for (int k=0; k<SIZE; ++k) {
			t += x(i, k) * y(k);
		}
		res(i) = 0;
	}
}
