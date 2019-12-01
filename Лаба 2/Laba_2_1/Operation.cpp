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

void changeNodes(Expression &last, Expression &preLast)
{
	
	string copyArg = last.getLastArg();
	char copyOper = last.getOperation();

	last.setLastArg(preLast.getFirstArg());
	last.setOperation(preLast.getOperation());

	preLast.setFirstArg(copyArg);
	preLast.setOperation(copyOper);
}

void changeArgs(Expression& last)
{
	string copy = last.getFirstArg();
	last.setFirstArg(last.getLastArg());
	last.setLastArg(copy);
}

Expression* updateSize(const Expression* exp, int size_old, int size_new)
{
	Expression* updateMass = NULL;
	updateMass = new Expression[size_new];
	if (updateMass) {
		size_t i = 0;

		//Если размер стека уменьшился
		if (size_new < size_old)
		{
			//Копируем все элементы за исключением последнего
			for (i = 0; i < size_new; i++)
			{
				updateMass[i] = exp[i];
			}
		}
		else {
			for (i = 0; i < size_old; i++)
			{
				updateMass[i] = exp[i];
			}

			for (; i < size_new; i++)
			{
				updateMass[i] = Expression();
			}
		}
	}

	return updateMass;
}

bool isCoorectExpression(const Expression& exp)
{
	Expression copy = Expression(exp);

	int countOper = 0, countArgs = 0;
	int i = -1;

	// Если первй аргумент не содержит символ операции
	while (copy.getFirstArg() != "" && copy.getCharOperation(copy.getFirstArg(), i) == ' ' && i == -1)
	{
		countOper++;
		countArgs++;
		if (copy.getLastArg() != "" && copy.getCharOperation(copy.getLastArg(), i) == ' ' && i == -1)
		{
			countArgs++;
			copy = Expression(copy.getLastArg());
		}
		else {
			break;
		}
	}

	if (countArgs - 1 == countOper)
		return true;
	else
		return false;
}
