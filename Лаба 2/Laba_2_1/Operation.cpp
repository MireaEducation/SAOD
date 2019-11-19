#include "Operation.h"

bool isExpression(string exp)
{
	int index = -1;
	Expression obj;

	obj.getCharOperation(exp, index);

	if (index == -1)
		return false;
	else
		return true;
}