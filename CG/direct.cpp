// let $d = \overrightarrow{P_0 P_2}\times\overrightarrow{P_0 P_1}$
// when $d < 0$, $\overrightarrow{P_0 P_1 P_2}$ is turn left
// when $d > 0$, $\overrightarrow{P_0 P_1 P_2}$ is turn right
// when $d = 0$, $\overrightarrow{P_0 P_1 P_2}$ is stright line
enum DIRECTION { LEFT = -1, STRIGHT = 0, RIGHT = 1 };
DIRECTION direct(Point2D P0, Point2D P1, Point2D P2) {
	return sign(outer(P2 - P0, P1 - P0));
}
int direct(Segment S, Point2D P) {
	return direct(S.p1, S.p2, P);
}
