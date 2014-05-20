// update lhs to maximum
template<typename value_type>
value_type & update_maximum(value_type & lhs, value_type const & rhs) {
	if (lhs < rhs) {
		lhs = rhs;
	}
	return lhs;
}
// update lhs to minimum
template<typename value_type>
value_type & update_minimum(value_type & lhs, value_type const & rhs) {
	if (rhs < lhs) {
		lhs = rhs;
	}
	return lhs;
}
// get maximum
template<typename value_type>
value_type const & maximum(value_type const & lhs, value_type const & rhs) {
	return rhs < lhs ? lhs : rhs;
}
// get minimum
template<typename value_type>
value_type const & minimum(value_type const & lhs, value_type const & rhs) {
	return lhs < rhs ? lhs : rhs;
}
// swap two values
template<typename value_type>
void swap(value_type & lhs, value_type & rhs) {
	value_type tmp = lhs;
	lhs = rhs;
	rhs = tmp;
}
// fill array
template<typename value_type>
void fill_range(value_type * begin, value_type * end, value_type const & value) {
	for (value_type * iterator = begin; iterator != end; ++iterator) {
		*iterator = value;
	}
}
// fill matrix
template<typename value_type>
void fill_matrix(value_type ** begin, int n, int m, value_type const & value) {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			weight[i * m + j] = INF;
		}
	}
}
int random() {
	static int seed = 0;
	static long long const a = 1103515245;
	static long long const c = 12345;
	seed = int(a * seed + c) & 0x0FFFFFFF;
	return seed;
}
