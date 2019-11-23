#include "StackHellper.h"

void StackHellper::init(stack<Expression> &mass, Expression elem,  string exp)
{
	mass.push(elem);

	//Если второй аргумент является мат. выражением - добавляем в стек
	while (isExpression(elem.getLastArg()))
	{
		Expression secondExp(elem.getLastArg());
		mass.push(secondExp);

		elem = secondExp;
	}
}
