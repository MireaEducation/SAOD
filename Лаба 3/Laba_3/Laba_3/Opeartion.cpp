#include "Opeartion.h"


int Fibonachi(int n, int sum_first, int sum_second, short& depth)
{
	if (n == depth) {
		return sum_first + sum_second;
	}
	else if (depth == 0) {
		depth++;
		return Fibonachi(n, 0, 1, depth);
	}
	else {
		depth++;
		return Fibonachi(n, sum_second, sum_first + sum_second, depth);
	}
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
	cout << "Введите значения для"<<n<<" элемента списка: "<<endl;
	cin >> head->value;

	cout << "\n\n";

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

