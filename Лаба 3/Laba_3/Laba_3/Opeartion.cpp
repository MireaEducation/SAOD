#include "Opeartion.h"


int Fibonachi(int n, int sum_first, int sum_second, int depth)
{
	if (n == depth) {
		return sum_first + sum_second;
	}
	else if (depth == 0) {
		return Fibonachi(n, 0, 1, depth + 1);
	}
	else {
		return Fibonachi(n, sum_second, sum_first + sum_second, depth + 1);
	}
}
