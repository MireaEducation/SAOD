#include "Operation.h"
#include <iostream>

using namespace std;

Telephone* createList(Telephone* head, int n)
{
	if (n == 0)
	{
		return head;
	}

	head = (Telephone*)malloc(sizeof(Telephone));

	cout << "Введите номер получателя: "; cin >> head->phoneFrom;
	cout << "Введите номер отправителя: "; cin >> head->phoneTo;
	cout << "Введите время разговора: "; cin >> head->timeTell;

	createList(head->next, n-1);
}

void showList(Telephone* list)
{
	if (list)
	{
		cout << "Номер отправителя: " << list->phoneFrom << "\tНомер получателя: " << node->list << "\tВремя разговора: " << node->list << endl;
		showList(list->next);
	}
}

Telephone* findNode(Telephone* current, int phoneFrom)
{
	if (current)
	{
		if (current->phoneFrom == phoneFrom)
		{
			return current;
		}
		return findNode(current->next, phoneFrom);
	}
	return nullptr;
}
