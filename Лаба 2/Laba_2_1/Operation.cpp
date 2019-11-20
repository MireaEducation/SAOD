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

void changeNodes(Expression& last, Expression& preLast)
{
	string copyArg = last.getLastArg();
	char copyOper = last.getOperation();

	last.setLastArg(preLast.getFirstArg());
	last.setOperation(copyOper);

	preLast.setFirstArg(copyArg);
	preLast.setOperation(copyOper);
}
