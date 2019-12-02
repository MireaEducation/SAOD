#include "Opeartion.h"

int Fibonachi(int n)
{
	if(!n) return 0;
	else if (n == 1 || n == 2) return 1;
	return Fibonachi(n - 1) + Fibonachi(n - 2);
}

LinkedList* CreateList(Node* head, int n)
{
	if (n == 0)
	{
		return nullptr;
	}

	head = (Node*)malloc(sizeof(Node));
	if (head == nullptr) {
		throw new exception("Не удалось выделить память под хранение указателя на элемент списка\n");
	}
	cout << "Введите значения для"<<n<<" элемента списка: ";
	cin >> head->value;

	head->next = CreateList(head->next, n - 1);

	return head;
}

void ClearList(Node* head)
{
	if (head->next != nullptr)
	{
		if (head->next->next != nullptr)
		{
			ClearList(head->next);
		}
		free(head->next);
	}
}

Node* FindNode(Node* current, int value)
{
	if (current)
	{
		if (current->value == value)
		{
			return current;
		}
		return FindNode(current->next, value);
	}
	return nullptr;
}

