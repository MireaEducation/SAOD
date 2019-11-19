#include "Expression.h"

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

Expression::Expression()
{
	this->firstArg = "";
	this->lastArg = "";
	this->operation = ' ';
}

Expression::Expression(string expression)
{
	int index = -1;

	this->operation = this->getCharOperation(expression, index);
	this->firstArg.append(expression.c_str(), index + 1);

	expression.erase(0, index + 1);

	this->lastArg = expression;
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
