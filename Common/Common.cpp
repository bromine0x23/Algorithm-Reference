template<class Tp>
void max_by_ref(Tp & lhs, Tp const & rhs) { if (lhs < rhs) { lhs = rhs; } }

template<class Tp>
void min_by_ref(Tp & lhs, Tp const & rhs) { if (lhs > rhs) { lhs = rhs; } }

template<class Tp>
Tp & max_by_val(Tp & lhs, Tp & rhs) { return lhs > rhs ? lhs : rhs; }

template<class Tp>
Tp & min_by_val(Tp & lhs, Tp & rhs) { return lhs < rhs ? lhs : rhs; }
