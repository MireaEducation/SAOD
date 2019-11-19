#include "Telephone.h"

Telephone::Telephone()
{
}

int Telephone::getPhoneFrom()
{
	return this->phoneFrom;
}

int Telephone::getPhoneTo()
{
	return this->phoneTo;
}

int Telephone::getTimeTell()
{
	return this->timeTell;
}

Telephone* Telephone::getNext()
{
	return this->next;
}

void Telephone::setPhoneFrom(int phoneFrom)
{
	this->phoneFrom = phoneFrom;
}

void Telephone::setPhoneTo(int phoneTo)
{
	this->phoneTo = phoneTo;
}

void Telephone::setTimeTell(int timeTell)
{
	this->timeTell = timeTell;
}

void Telephone::setNext(Telephone* next)
{
	this->next = next;
}
