#include "StackDynamic.h"

StackDynamic::StackDynamic()
{
	this->mass = nullptr;
	this->size = 0;
}

StackDynamic::~StackDynamic()
{
	if (mass != nullptr && this->size != 0)
		free(mass);
}

void StackDynamic::init(string exp)
{
	this->mass = new Expression[1];
	this->size = 1;

	
	while(!this->mass) this->mass = new Expression[1];

	if (this->mass) {
		Expression obj(exp);
		this->mass[0] = obj;

		if (obj.isPriorityOperation() && isExpression(obj.getLastArg()))
		{
			Expression expNew(obj.getLastArg());
			Expression exp = Expression(
				obj.getFirstArg() +
				obj.getOperation() +
				Expression(obj.getLastArg()).getFirstArg()
			);

			expNew.setFirstArg(to_string(exp.getResult()));

			this->mass[0] = obj = expNew;
		}

		//Если второй аргумент является мат. выражением - добавляем в стек
		while (isExpression(obj.getLastArg()))
		{
			Expression secondExp(obj.getLastArg());

			if (secondExp.isPriorityOperation() && isExpression(secondExp.getLastArg()))
			{
				Expression expNew(secondExp.getLastArg());
				Expression exp = Expression(
					secondExp.getFirstArg() +
					secondExp.getOperation() +
					Expression(secondExp.getLastArg()).getFirstArg()
				);

				expNew.setFirstArg(to_string(exp.getResult()));

				obj = secondExp = expNew;
			}

			this->push(secondExp);
			obj = secondExp;
		}
	}
	else {
		throw new exception("Не удалось выделить память \n");
	}
}

void StackDynamic::push(Expression elem)
{
	this->mass = updateSize(this->mass, this->size, this->size + 1);
	this->size++;

	if (this->mass) {
		this->mass[size - 1] = elem;
	}
	else {
		throw new exception("Не удалось выделить память \n");
	}
}

void StackDynamic::pop()
{
	this->mass = updateSize(this->mass, this->size, this->size - 1);
	this->size--;
}

Expression StackDynamic::top()
{
	if (this->size != 0)
		return this->mass[this->size - 1];
	else
		return Expression();
}

double StackDynamic::getResultExpression()
{
	Expression hellper;

	//Пробегаемся с конца стека, удаляя посчитанные значения
	while (this->size != 1)
	{
		int indexLast= this->size - 1;//индекс последнего выражения

		Expression *last = &this->mass[indexLast];
		Expression *preLast = &this->mass[indexLast - 1];
		Expression* prePreLast = &this->mass[indexLast - 2];

		//Если знак операции последнего элемента стека - имеет высокий приоритет
		if (last->isPriorityOperation() || (!preLast->isPriorityOperation() && preLast->getOperation() != '-'))
		{
			preLast->setLastArg(to_string(last->getResult()));
		}
		else if (preLast->getOperation() == '-') {
			//Если оба числа отрицательны
			if (last->getOperation() == '-')
			{
				last->setOperation('+');
				preLast->setLastArg(to_string(last->getResult()));
			}
			else {
				//changeNodes(*last, *preLast);
				last->setOperation('-');

				//Меняем местами аргументы в связи обнаруженным минусом
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

			if (prePreLast->getOperation() == '-')
			{
				preLast->setOperation('-');
				prePreLast->setOperation('+');
				preLast->setLastArg(to_string(last->getResult()));
			}
			else {
				preLast->setLastArg(to_string(last->getResult()));
				if (preLast->getOperation() == '-') {
					changeArgs(*preLast);
				}
			}
		}
		this->pop();
	}
	return this->mass[0].getResult();
}
