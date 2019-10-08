#include "Operation.h"
#include <iostream>

using namespace std;

Node* createList(Node* head, int n)
{
	if (n == 0)
	{
		return nullptr;
	}

	head = (Node*)malloc(sizeof(Node));

	cout << "Введите номер получателя: "; cin >> head->phoneFrom;
	cout << "Введите номер отправителя: "; cin >> head->phoneTo;
	cout << "Введите время разговора: "; cin >> head->timeTell;

	head->next = createList(head->next, n - 1);

	return head;
}

void showList(Node* list)
{
	if (list)
	{
		cout << "Номер отправителя: " << list->phoneFrom << "\tНомер получателя: " << list->phoneTo << "\tВремя разговора: " << list->timeTell << endl;
		showList(list->next);
	}
}

Node* findNode(Node* current, int phoneFrom)
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
