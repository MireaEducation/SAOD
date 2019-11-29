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

void PrintTree(BinaryTreeNode* p, int level)
{
	if (p)
	{
		PrintTree(p->right, level + 1);
		for (size_t i = 0; i < level; i++) cout << "\t";
		cout << p->data <<"-"<<(p->color == NodeColor::Black ? "Black" : "Red")<< endl;
		PrintTree(p->left, level + 1);
	}
}
