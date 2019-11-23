#include "StackHellper.h"

void StackHellper::init(stack<Expression> &mass, Expression elem,  string exp)
{
	mass.push(elem);

	//≈сли второй аргумент €вл€етс€ мат. выражением - добавл€ем в стек
	while (isExpression(elem.getLastArg()))
	{
		Expression secondExp(elem.getLastArg());
		mass.push(secondExp);

		elem = secondExp;
	}
}

double StackHellper::getResultExpression(stack<Expression>& mass)
{
	Expression hellper;

	//ѕробегаемс€ с конца стека, удал€€ посчитанные значени€
	while (mass.size() != 1)
	{
		int indexLast = mass.size() - 1;//индекс последнего выражени€

		Expression* last = &mass.top(); mass.pop();
		Expression* preLast = &mass.top();

		//≈сли знак операции последнего элемента стека - имеет высокий приоритет
		if (last->isPriorityOperation() || (!preLast->isPriorityOperation() && preLast->getOperation() != '-'))
		{
			preLast->setLastArg(to_string(last->getResult()));
		}
		else if (preLast->getOperation() == '-') {
			//≈сли оба числа отрицательны
			if (last->getOperation() == '-')
			{
				last->setOperation('+');
				preLast->setLastArg(to_string(last->getResult()));
			}
			else {
				//changeNodes(*last, *preLast);
				last->setOperation('-');

				//ћен€ем местами аргументы в св€зи обнаруженным минусом
				changeArgs(*last);
				double res = last->getResult();
				if (res < 0)
				{
					preLast->setOperation('-');
				}
				else {
					preLast->setOperation('+');
				}
				preLast->setLastArg(to_string(abs(res)));
			}
		}
		else {
			changeNodes(*last, *preLast);
			changeArgs(*last);

			preLast->setLastArg(to_string(last->getResult()));
			if (preLast->getOperation() == '-') {
				changeArgs(*preLast);
			}
		}
		//this->pop();
	}
	return mass.top().getResult();//this->mass[0].getResult();
}
