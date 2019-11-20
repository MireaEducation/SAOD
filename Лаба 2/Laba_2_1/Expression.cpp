#include "Expression.h"

Expression::Expression()
{
	this->firstArg = "";
	this->lastArg = "";
	this->operation = ' ';
}

Expression::Expression(string expression)
{
	int index = -1;

	this->operation = getCharOperation(expression, index);
	this->firstArg.append(expression.c_str(), index);

	expression.erase(0, index + 1);

	this->lastArg = expression;
}

char Expression::getCharOperation(string exp, int& index)
{
	int length = exp.length();
	char oper = ' ';

	for (size_t i = 0; i < length; i++)
	{
		if (exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/')
		{
			oper = exp[i];
			index = i;
			break;
		}
	}

	return oper;
}


double Expression::getResult()
{
	double arg1 = atof(this->firstArg.c_str());
	double arg2 = atof(this->lastArg.c_str());

	switch (this->operation)
	{
	case '+':
		return arg1 + arg2;
		break;
	case '-':
		return arg1 - arg2;
		break;
	case '*':
		return arg1 * arg2;
		break;
	case '/':
		if (arg2 != 0)
			return arg1 + arg2;
		else
			throw new exception("Ошибка - выражение содержит операцию деления на 0");
		break;
	default:
		throw new exception("Ошибка - неверный символ операции");
		break;
	}
}

bool Expression::isPriorityOperation()
{
	if (this->operation == '*' || this->operation == '/')
		return true;
	else
		return false;
}

string Expression::getLastArg()
{
	return this->lastArg;
}

string Expression::getFirstArg()
{
	return this->firstArg;
}

char Expression::getOperation()
{
	return this->operation;
}

void Expression::setLastArg(string lastArg)
{
	this->lastArg = lastArg;
}

void Expression::setFirstArg(string firstArg)
{
	this->firstArg = firstArg;
}

void Expression::setOperation(char operation)
{
	this->operation = operation;
}
