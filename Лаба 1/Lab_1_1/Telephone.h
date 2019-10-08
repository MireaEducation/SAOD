#pragma once
typedef struct Telephone
{
	//Номер отправителя
	int phoneFrom;

	//Номер получателя
	int phoneTo;

	//Ссылка на следующий элемент списка
	struct Telephone* next;
} lstTelephone;