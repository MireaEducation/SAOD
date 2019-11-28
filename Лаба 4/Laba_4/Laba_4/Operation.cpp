#include "Operation.h"


void CreateTree(RedBlackTree* root, int n)
{
	for (size_t i = 0; i < n; i++)
	{
		cout << "¬ведите значение дл€ " << i << " узла: ";
		char value = ' ';
		cin >> value;
		root->InsertNode(value);
	}
}
