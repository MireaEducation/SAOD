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

	cout << "Осталость добавить: " << n << endl;
	cout << "Введите номер получателя: "; cin >> head->phoneFrom;
	
	{
		int res = head->phoneFrom;
		int minValue = res / 1000000;
		int maxValue = res / 10000000;
		while ( !(minValue > 0 && maxValue == 0) )
		{
			cout << "Номер телефона долежн состоять из 7 цифр !\nПовторите ввод: ";
			cin >> res;
			minValue = res / 1000000;
			maxValue = res / 10000000;
		}
		head->phoneFrom = res;
	}
	
	cout << "Введите номер отправителя: "; cin >> head->phoneTo;
	cout << "Введите время разговора: "; cin >> head->timeTell;
	cout << "\n\n";

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

Node* getLastNode(Node* current)
{
	if (current)
	{
		if (current->next)
		{
			return getLastNode(current->next);
		}
		return current;
	}
	return nullptr;
}

void addNode(Node* lastNode, Node* nodeNew)
{
	nodeNew = createList(nodeNew, 1);
	lastNode->next = nodeNew;
}

int getNum(int phone)
{
	int num1 = (phone / 1000000);
	int num2 = (phone / 100000) % 10;
	int num3 = (phone / 10000) % 10;
	return num1*100+num2*10+num3;
}

void swapDataNode(Node* node1, Node* node2)
{
	int phoneFrom = node1->phoneFrom, 
		phoneTo = node1->phoneTo,
		timeTell = node1->timeTell;

	node1->phoneFrom = node2->phoneFrom;
	node1->phoneTo = node2->phoneTo;
	node1->timeTell = node2->timeTell;

	node2->phoneFrom = phoneFrom;
	node2->phoneTo = phoneTo;
	node2->timeTell = timeTell;
}

void sortList(Node* head)
{
	Node* first = head, * second = 0;
	for (second = head; second; second = second->next)
	{ 
		for (first = head; first->next; first = first->next)
		{
			if (getNum(first->phoneFrom) > getNum(first->next->phoneFrom))
			{
				swapDataNode(first, first->next);
			}
		}
	}
}

Node* getLastNodeForDelete(Node* head, int phoneFrom)
{
	Node* last = nullptr;
	for (Node* i = head; i->next; i = i->next)
	{
		if (i->phoneFrom = phoneFrom)
		{
			last = i;
		}
	}
	return last;
}

void deletChoosenNode(Node* head)
{
	int phoneFrom;
	cout << "Введите номер телефона отправителя: "; cin >> phoneFrom;
	Node* last = getLastNodeForDelete(head, phoneFrom);
	for (Node* i = head; i->next; i = i->next)
	{
		if (i == last)
		{
			i->next = i->next->next;
			free(i->next);
			return;
		}
	}
}

int sumTimeTell(Node* head, int phoneFrom)
{
	int sum = 0;
	for (Node* i = head; i; i = i->next)
	{
		if (i->phoneFrom == phoneFrom)
			sum += i->timeTell;
	}
	return sum;
}
