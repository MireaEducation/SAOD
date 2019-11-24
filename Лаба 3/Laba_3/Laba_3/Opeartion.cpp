#include "Opeartion.h"


int Fibonachi(int n, int sum_first, int sum_second, short& depth)
{
	if (n == depth) {
		return sum_first + sum_second;
	}
	else if (depth == 0) {
		depth++;
		return Fibonachi(n, 0, 1, depth);
	}
	else {
		depth++;
		return Fibonachi(n, sum_second, sum_first + sum_second, depth);
	}
}
