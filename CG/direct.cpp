// let $d = \overrightarrow{P_0 P_2}\times\overrightarrow{P_0 P_1}$
// when $d < 0$, $\overrightarrow{P_0 P_1 P_2}$ is turn left
// when $d > 0$, $\overrightarrow{P_0 P_1 P_2}$ is turn right
// when $d = 0$, $\overrightarrow{P_0 P_1 P_2}$ is stright line
enum DIRECTION { LEFT = -1, STRIGHT = 0, RIGHT = 1 };
DIRECTION direct(Point2D const & p0, Point2D const & p1, Point2D const & p2) {
	return sign(outer(p2 - p0, p1 -p0));
}
int direct(Segment const & S, Point2D const & P) {
	return direct(S.p1, S.p2, P);
}
