#pragma once
typedef struct Telephone
{
	//Номер отправителя
	int phoneFrom;

	//Номер получателя
	int phoneTo;

	//Время разговора в минутах
	int timeTell;

	//Ссылка на следующий элемент списка
	struct Telephone* next;
} lstTelephone;