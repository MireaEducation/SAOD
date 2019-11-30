#include "Operation.h"


void CreateTree(RedBlackTree* root, int n)
{
	for (size_t i = 0; i < n; i++)
	{
		cout << "Введите значение для " << i << " узла: ";
		char value = ' ';
		cin >> value;
		root->InsertNode(value);
	}
}

void PrintTree(BinaryTreeNode* p, int level)
{
	if (p && p->data != ' ')
	{
		PrintTree(p->right, level + 1);
		for (size_t i = 0; i < level; i++) cout << "\t";
		cout << (int)p->data <<"-"<<(p->color == NodeColor::Black ? "Black" : "Red")<< endl;
		PrintTree(p->left, level + 1);
	}
}

int InOrderTravelRL(BinaryTreeNode* root, int sum)
{
	// Если данный узел не NIL
	if (root && root->data != ' ')
	{
		sum = (int)root->data;
	} else return 0;

	sum += InOrderTravelRL(root->right, sum);
	sum += InOrderTravelRL(root->left, sum);
	
	return sum;
}
