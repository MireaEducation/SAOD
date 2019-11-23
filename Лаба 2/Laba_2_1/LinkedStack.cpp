#include "LinkedStack.h"

LinkedStack* LinkedStack::preTop()
{
	LinkedStack ptr = *this;
	while (ptr.next != nullptr && ptr.next->next != nullptr)
	{
		ptr = *ptr.next;
	}
	return &ptr;
}

LinkedStack::LinkedStack(Expression elem)
{
	this->next = nullptr;
	this->value = elem;

	if (this->value.getOperation() != ' ') {

		//≈сли второй аргумент €вл€етс€ мат. выражением - добавл€ем в стек
		while (isExpression(elem.getLastArg()))
		{
			Expression secondExp(elem.getLastArg());
			this->push(secondExp);
			elem = secondExp;
		}
	}
	else {
		throw new exception("Ќе удалось выделить пам€ть \n");
	}
}

LinkedStack::~LinkedStack()
{
	if (this->next != nullptr)
		free(this->next);
}

void LinkedStack::push(Expression elem)
{
	LinkedStack* stack = new LinkedStack(elem);
	this->next = stack;
}

void LinkedStack::pop()
{

}

LinkedStack* LinkedStack::top()
{
	LinkedStack ptr = *this;
	while (ptr.next != nullptr)
	{
		ptr = *ptr.next;
	}
	return &ptr;
}

double LinkedStack::getResultExpression()
{
	Expression hellper;

	//ѕробегаемс€ с конца стека, удал€€ посчитанные значени€
	while (this->next != nullptr)
	{
		Expression* last = &this->top()->value;
		Expression* preLast = &this->preTop()->value;

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
		this->pop();
	}
	return this->value.getResult();
}
