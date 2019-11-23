#include "LinkedStack.h"

LinkedStack::LinkedStack(Expression elem)
{
	this->next = nullptr;
	this->value = elem;

	if (this->value.getOperation() != ' ') {

		//Если второй аргумент является мат. выражением - добавляем в стек
		while (isExpression(elem.getLastArg()))
		{
			Expression secondExp(elem.getLastArg());
			this->push(secondExp);
			elem = secondExp;
		}
	}
	else {
		throw new exception("Не удалось выделить память \n");
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
	return 0.0;
}
