#include "Stack.h"

Stack::Stack(string exp)
{
	this->mass = (Expression*)malloc(1);
	this->size = 1;
}

void Stack::push(Expression elem)
{
	this->size++;
	this->mass = (Expression*)realloc(this->mass, this->size);

	if (this->mass) {
		throw new exception("Не удалось выделить память \nStack.cpp: 13 строка");
	}
	else {
		this->mass[size - 1] = elem;
	}
}
