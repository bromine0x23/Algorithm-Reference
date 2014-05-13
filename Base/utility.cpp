template<typename value_type>
value_type & update_maximum(value_type & lhs, value_type const & rhs) {
	if (lhs < rhs) {
		lhs = rhs;
	}
	return lhs;
}
template<typename value_type>
value_type & update_minimum(value_type & lhs, value_type const & rhs) {
	if (rhs < lhs) {
		lhs = rhs;
	}
	return lhs;
}
template<typename value_type>
value_type & maximum(value_type & lhs, value_type & rhs) {
	return rhs < lhs ? lhs : rhs;
}
template<typename value_type>
value_type & minimum(value_type & lhs, value_type & rhs) {
	return lhs < rhs ? lhs : rhs;
}
template<typename value_type>
void swap(value_type & lhs, value_type & rhs) {
	value_type tmp = lhs;
	lhs = rhs;
	rhs = tmp;
}
