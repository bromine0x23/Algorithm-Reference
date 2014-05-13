template<typename value_type, int size>
struct Row {
	value_type r[size];
	Row() {
		for (int j = 0; j < size; ++j) {
			r[j] = 0;
		}
	}
	value_type & operator()(int j) {
		return r[j];
	}
	value_type const & operator()(int j) const {
		return r[j];
	}
	Row & operator=(Row const & y) {
		for (int j = 0; j < size; ++j) {
			r[j] = y(j);
		}
		return *this;
	}
};
template<typename value_type, int size>
struct Column {
	value_type c[size];
	Column() {
		for (int i = 0; i < size; ++i) {
			c[i] = 0;
		}
	}
	value_type & operator()(int i) {
		return c[i];
	}
	value_type const & operator()(int i) const {
		return c[i];
	}
	Column & operator=(Column const & y) {
		for (int i = 0; i < size; ++i) {
			c[i] = y(i);
		}
		return *this;
	}
};
template<typename value_type, int size>
struct Square {
	value_type s[size][size];
	Square() {
		for (int i = 0; i < size; ++i) {
			for (int j = 0; j < size; ++j) {
				s[i][j] = 0;
			}
		}
	}
	value_type & operator()(int i, int j) {
		return s[i][j];
	}
	value_type operator()(int i, int j) const {
		return s[i][j];
	}
	Square & operator=(Square const & y) {
		for (int i = 0; i < size; ++i) {
			for (int j = 0; j < size; ++j) {
				s[i][j] = y(i, j);
			}
		}
		return *this;
	}
	Square & operator+=(Square const & y) {
		for (int i = 0; i < size; ++i) {
			for (int j = 0; j < size; ++j) {
				s[i][j] += y(i, j);
			}
		}
		return *this;
	}
	Square & operator*=(int y) {
		for (int i = 0; i < size; ++i) {
			for (int j = 0; j < size; ++j) {
				s[i][j] += y;
			}
		}
		return *this;
	}

	Square operator-() const {
		Square square;
		for (int i = 0; i < size; ++i) {
			for (int j = 0; j < size; ++j) {
				square(i, j) = -s[i][j];
			}
		}
		return square;
	}
	Square operator~() const {
		Square square;
		for (int i = 0; i < size; ++i) {
			for (int j = 0; j < size; ++j) {
				square(i, j) = s[j][i];
			}
		}
		return *this;
	}
	static Square identity() {
		Square square;
		for (int i = 0; i < size; ++i) {
			for (int j = 0; j < size; ++j) {
				square(i, j) = (i == j ? 1 : 0);
			}
		}
		return square;
	}
};
template<typename value_type, int size>
Square<value_type, size> operator*(Square<value_type, size> const & x, Square<value_type, size> const & y) {
	Square<value_type, size> square;
	for (int i = 0; i < size; ++i) {
		for (int j = 0; j < size; ++j) {
			value_type t = 0;
			for (int k = 0; k < size; ++k) {
				t += x(i, k) * y(k, j);
			}
			square(i, j) = t;
		}
	}
	return square;
}
template<typename value_type, int size>
Row<value_type, size> operator*(Row<value_type, size> const & x, Square<value_type, size> const & y) {
	Row<value_type, size> row;
	for (int j = 0; j < size; ++j) {
		value_type t = 0;
		for (int k = 0; k < size; ++k) {
			t += x(k) * y(k, j);
		}
		row(j) = t;
	}
	return row;
}
template<typename value_type, int size>
Column<value_type, size> operator*(Square<value_type, size> const & x, Column<value_type, size> const & y) {
	Column<value_type, size> column;
	for (int i = 0; i < size; ++i) {
		value_type t = 0;
		for (int k = 0; k < size; ++k) {
			t += x(i, k) * y(k);
		}
		column(i) = t;
	}
	return column
}
