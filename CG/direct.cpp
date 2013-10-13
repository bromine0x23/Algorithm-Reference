// let $d = \overrightarrow{P_0 P_2}\times\overrightarrow{P_0 P_1}$
// when $d < 0$, $\overrightarrow{P_0 P_1 P_2}$ is turn left
// when $d > 0$, $\overrightarrow{P_0 P_1 P_2}$ is turn right
// when $d = 0$, $\overrightarrow{P_0 P_1 P_2}$ is stright line
int direct(Point const & p0, Point const & p1, Point const & p2) {
	return sign(cross(p2 - p0, p1 -p0));
}

int direct(Segment const & S, Point const & P) {
	return direct(S.p1, S.p2, P);
}
