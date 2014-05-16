// $O(\log n)$, calculate Fibonacci number using matrix multiplcate
struct FibonacciMatrix22{
	int a11, a12, a21, a22; // $\left(\begin{smallmatrix} a_{11} & a_{12} \\ a_{21} & a_{22} \end{smallmatrix}\right)$
};
FibonacciMatrix22 matrix_mul(FibonacciMatrix22 const & lhs, FibonacciMatrix22 const & rhs) {
	// expand matrix multiplcate
	FibonacciMatrix22 result = {
		lhs.a11 * rhs.a11 + lhs.a12 * rhs.a21,
		lhs.a11 * rhs.a12 + lhs.a12 * rhs.a22,
		lhs.a21 * rhs.a11 + lhs.a22 * rhs.a21,
		lhs.a21 * rhs.a12 + lhs.a22 * rhs.a22,
	};
	return result;
}
int fibonacci(int n) {
	FibonacciMatrix22 A = {0, 1, 1, 1};
	FibonacciMatrix22 F = {1, 0, 0, 1};
	for (; n != 0; n /= 2) {
		if (n % 2 == 1) {
			F = matrix_mul(F, A);
		}
		A = matrix_mul(A, A);
	}
	return F.a12; // or $a_{21}$
}
