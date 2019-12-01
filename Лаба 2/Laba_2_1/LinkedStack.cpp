#include "LinkedStack.h"

LinkedStack* LinkedStack::preTop()
{
	LinkedStack* ptr = this;
	while (ptr->next != nullptr && ptr->next->next != nullptr)
	{
		ptr = ptr->next;
	}
	return ptr;
}

LinkedStack* LinkedStack::prePreTop()
{
	LinkedStack* ptr = this;
	while (ptr->next != nullptr && ptr->next->next != nullptr && ptr->next->next->next != nullptr)
	{
		ptr = ptr->next;
	}
	return ptr;
}

LinkedStack::LinkedStack(Expression elem)
{
	this->next = nullptr;
	this->value = elem;

	if (elem.isPriorityOperation() && isExpression(elem.getLastArg()))
	{
		Expression expNew(elem.getLastArg());
		Expression exp = Expression(
			elem.getFirstArg() +
			elem.getOperation() +
			Expression(elem.getLastArg()).getFirstArg()
		);

		expNew.setFirstArg(to_string(exp.getResult()));

		this->value = elem = expNew;
	}

	if (elem.getOperation() != ' ') {

		//Если второй аргумент является мат. выражением - добавляем в стек
		if (isExpression(elem.getLastArg()))
		{
			elem = Expression(elem.getLastArg());

			this->push(elem);
		}
	}
	else {
		throw  exception("Не удалось выделить память \n");
	}
}

LinkedStack::~LinkedStack()
{
	if (this->next != nullptr)
		free(this->next);
}

void LinkedStack::push(Expression elem)
{
	LinkedStack* stack = this->top();
	stack->next = new LinkedStack(elem);
}

void LinkedStack::pop()
{
	LinkedStack* preLast = this->preTop();
	free(preLast->next);
	preLast->next = nullptr;
}

LinkedStack* LinkedStack::top()
{
	LinkedStack* ptr = this;
	while (ptr->next != nullptr)
	{
		ptr = ptr->next;
	}
	return ptr;
}

double LinkedStack::getResultExpression(LinkedStack* head)
{
	Expression hellper;

	//Пробегаемся с конца стека, удаляя посчитанные значения
	while (this->top() != head)
	{
		Expression* last = &this->top()->value;
		Expression* preLast = &this->preTop()->value;
		Expression* prePreLast = &this->prePreTop()->value;

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
		else {//Если операция / или *
			
			changeNodes(*last, *preLast);
			changeArgs(*last);

			if (prePreLast != preLast && prePreLast->getOperation() == '-')
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
	return this->value.getResult();
}
