bool intersect(Segment const & s1, Segment const & s2) {
	int d1 = direct(s2, s1.p1);
	int d2 = direct(s2, s1.p2);
	int d3 = direct(s1, s2.p1);
	int d4 = direct(s1, s2.p2);
	if (d1 * d2 == -1 && d3 * d4 == -1) {
		return true;
	} else if (d1 == 0 && on_segment(s2, s1.p1)) {
		return true;
	} else if (d2 == 0 && on_segment(s2, s1.p2)) {
		return true;
	} else if (d3 == 0 && on_segment(s1, s2.p1)) {
		return true;
	} else if (d4 == 0 && on_segment(s1, s2.p2)) {
		return true;
	} else {
		return false;
	}
}
bool on_segment(Segment const & s, Point const p) {
	return
		minimum(s.p1.x, s.p2.x) <= p.x && p.x <= maximum(s.p1.x, s.p2.x) &&
		minimum(s.p1.y, s.p2.y) <= p.y && p.y <= maximum(s.p1.y, s.p2.y);
}
